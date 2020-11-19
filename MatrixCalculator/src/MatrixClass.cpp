#include "MatrixClass.h"
#include <exception>
#include <iomanip>
#include <cmath>

const std::string ERROR_MSG{ "Invalid argument! Operation cannot be performed."};
const std::string INVERSE_ERROR{ "This matrix doesn't have an inverse!" };

Matrix::Matrix(std::vector<std::vector<double>> matrix) : m_matrix{ matrix }
{
}

double Matrix::calculateDeterminant() const
{
    if (!squareMatrix()) {

        std::invalid_argument error(ERROR_MSG);
        throw error;

    }else if (m_matrix.size() == 1) {

        return m_matrix[0][0];

    }else if (m_matrix.size() == 2) {
        return m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1];
    }
    // initialize Sum to zero
    double running_sum{ 0 };
    // loop to traverse each column of matrix a
    for (int col = 0; col < m_matrix.size(); col++) {
        // calculating the sign corresponding to co - factor of that sub matrix.
        double sign = std::pow(-1.0, col);

        // calling the function recursively to
        // get determinant value of a sub-matrix obtained
        double sub_determinant = cofactor(m_matrix, 0, col).calculateDeterminant();
        // adding the calculated determinant to the total sum
        running_sum += (sign * m_matrix[0][col] * sub_determinant);
    }
    return running_sum;
}

bool Matrix::squareMatrix() const
{
    return m_matrix.size() != 0 && m_matrix.size() == m_matrix[0].size();
}

Matrix Matrix::cofactor(std::vector<std::vector<double>> matrix, size_t rowIdx, size_t colIdx) const
{
    // initialize matrix - one row smaller than the input matrix
	std::vector<std::vector<double>> newMatrix(matrix.size() - 1, std::vector<double>{});
    // iterate through the matrix to get cofactor
	for (int row = 0; row < rowIdx; row++) {
		newMatrix[row].insert(newMatrix[row].end(), matrix[row].begin(), matrix[row].begin() + colIdx);
        // skip column at "colIdx"
		newMatrix[row].insert(newMatrix[row].end(), matrix[row].begin() + colIdx + 1, matrix[row].end());
	}
    // skip row at "rowIdx"
	for (int row = rowIdx + 1; row < matrix.size(); row++) {
		newMatrix[row-1].insert(newMatrix[row-1].end(), matrix[row].begin(), matrix[row].begin() + colIdx);
        // skip column at "colIdx"
		newMatrix[row-1].insert(newMatrix[row-1].end(), matrix[row].begin() + colIdx + 1, matrix[row].end());
	}
	return Matrix(newMatrix);
}


Matrix Matrix::operator+(const Matrix& other) const
{
    if (other.m_matrix.size() != m_matrix.size() || other.m_matrix[0].size() != m_matrix[0].size()) {
        std::invalid_argument error(ERROR_MSG);
        throw error;
    }
    Matrix sum;
    for (int i = 0; i < m_matrix.size(); i++) {
        std::vector<double> newRow{};
        for (int j = 0; j < m_matrix[0].size(); j++) {
            newRow.push_back(m_matrix[i][j] + other.m_matrix[i][j]);
        }
        sum.m_matrix.push_back(newRow);
    }
    return sum;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    if (other.m_matrix.size() != m_matrix.size() || other.m_matrix[0].size() != m_matrix[0].size()) {
        std::invalid_argument error(ERROR_MSG);
        throw error;
    }
    Matrix diff;
    for (int i = 0; i < m_matrix.size(); i++) {
        std::vector<double> newRow{};
        for (int j = 0; j < m_matrix[0].size(); j++) {
            newRow.push_back(m_matrix[i][j] - other.m_matrix[i][j]);
        }
        diff.m_matrix.push_back(newRow);
    }
    return diff;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    // The number of columns of the 1st matrix must equal the number of rows of the 2nd matrix
    if (m_matrix[0].size() != other.m_matrix.size()) {
        std::invalid_argument error(ERROR_MSG);
        throw error;
    }
    // initialize product matrix - nr of rows from the 1st matrix and 
    // nr of columns from the 2nd matrix
    Matrix product(std::vector<std::vector<double>>(m_matrix.size(),
        std::vector<double>(other.m_matrix[0].size(), 0)));
    // do the dot product of rows and columns
    for (int x = 0; x < m_matrix.size(); x++) {
        for (int y = 0; y < other.m_matrix[0].size(); y++) {
            for (int z = 0; z < other.m_matrix.size(); z++) {
                product[x][y] += m_matrix[x][z] * other.m_matrix[z][y];
            }
        }
    }
    return product;
}

Matrix Matrix::operator*(const double& scalar) const
{
    // initialize a copy of the matrix
    Matrix product{ *this };
    // multiply each element of Matrix by scalar
    for (int x = 0; x < m_matrix.size(); x++) {
        for (int y = 0; y < m_matrix[0].size(); y++) {
            product[x][y] = m_matrix[x][y] * scalar;
        }
    }
    return product;
}

void Matrix::operator+=(Matrix& other)
{
    if (other.m_matrix.size() != m_matrix.size() || other.m_matrix[0].size() != m_matrix[0].size()) {
        std::invalid_argument error(ERROR_MSG);
        throw error;
    }
    for (int i = 0; i < m_matrix.size(); i++) {
        for (int j = 0; j < m_matrix[0].size(); j++) {
            m_matrix[i][j] += other.m_matrix[i][j];
        }
    }
}

void Matrix::operator-=(Matrix& other)
{
    if (other.m_matrix.size() != m_matrix.size() || other.m_matrix[0].size() != m_matrix[0].size()) {
        std::invalid_argument error(ERROR_MSG);
        throw error;
    }
    for (int i = 0; i < m_matrix.size(); i++) {
        for (int j = 0; j < m_matrix[0].size(); j++) {
            (*this)[i][j] -= other[i][j];
        }
    }
}

void Matrix::operator*=(Matrix& other)
{
    // The number of columns of the matrix must equal the number of rows of the other matrix
    if (m_matrix[0].size() != other.m_matrix.size()) {
        std::invalid_argument error(ERROR_MSG);
        throw error;
    }
    // initialize product matrix
    Matrix product(std::vector<std::vector<double>>(m_matrix.size(), 
        std::vector<double>(other.m_matrix[0].size(), 0)));
    // do the dot product of rows and columns
    for (int x = 0; x < m_matrix.size(); x++) {
        for (int y = 0; y < other.m_matrix[0].size(); y++) {
            for (int z = 0; z < other.m_matrix.size(); z++) {
                product[x][y] += (*this)[x][z] * other[z][y];
            }
        }
    }
    *this = product;
}

void Matrix::operator*=(double& scalar)
{
    // multiply each element of Matrix by scalar
    for (int x = 0; x < m_matrix.size(); x++) {
        for (int y = 0; y < m_matrix[0].size(); y++) {
            (*this)[x][y] *= scalar;
        }
    }
}

void Matrix::operator()(std::vector<std::vector<double>>&& vec)
{
    m_matrix = vec;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
    for (auto row : matrix.m_matrix) {
        for (auto ele : row) {
            out << std::setw(3) << std::setprecision(2) << ele << " ";
        }
        out << std::endl;
    }
    return out;
}

std::vector<std::vector<double>>& operator>>(std::vector<std::vector<double>>& vec, Matrix& matrix)
{
    matrix.m_matrix = vec;
    return vec;
}

std::vector<double>& Matrix::operator[](const size_t& idx)
{
    return m_matrix[idx];
}
// Transpose matrix about main diagonal
Matrix Matrix::transposeMain() const
{
    std::vector<std::vector<double>>transposed{m_matrix[0].size(),
        std::vector<double>{}};
    for (int x = 0; x < m_matrix.size(); x++) {
        for (int y = 0; y < m_matrix[x].size(); y++) {
            transposed[y].push_back(m_matrix[x][y]);
        }
    }
    return Matrix(transposed);
}
// Transpose matrix about secondary diagonal
Matrix Matrix::transposeSide() const
{
    std::vector<std::vector<double>>transposed{ m_matrix[0].size(),
        std::vector<double>{} };
    for (int x = m_matrix.size() - 1; x >= 0; x--) {
        for (int y = m_matrix[x].size() - 1, z = 0; y >= 0; y--, z++) {
            transposed[y].push_back(m_matrix[x][z]);
        }
    }
    return Matrix(transposed);
}
// Transpose matrix about vertical line
Matrix Matrix::transposeVertical() const
{
    Matrix transposed{ *this };
    for (int x = 0; x < m_matrix.size(); x++) {
        for (int y = 0, z = m_matrix[x].size() - 1; y < m_matrix[x].size(); y++, z-- ) {
            transposed[x][y] = m_matrix[x][z];
        }
    }
    return Matrix(transposed);
}
// Transpose matrix about horizontal line
Matrix Matrix::transposeHorizontal() const
{
    Matrix transposed{ *this };
    for (int x = 0, z = m_matrix.size() - 1; x < m_matrix.size(); x++, z--) {
        for (int y = 0; y < m_matrix[x].size(); y++) {
            transposed[x][y] = m_matrix[z][y];
        }
    }
    return Matrix(transposed);
}
// TO DO!!!!
Matrix Matrix::inverse() const
{
    double determinant{calculateDeterminant()};
    // check if the matrix has an inverse
    if (determinant == 0 || !squareMatrix() || m_matrix.size() == 1) {
        std::invalid_argument error(INVERSE_ERROR);
        throw error;
    }
    // special case for 2x2 matrix:
    else if (squareMatrix() && m_matrix.size() == 2) {
        std::vector<std::vector<double>> inversed{
            {m_matrix[1][1] / determinant , -1 * m_matrix[0][1] / determinant},
            {-1 * m_matrix[1][0] / determinant, m_matrix[0][0] / determinant }
        };
        return Matrix(inversed);
    }
    else {
        // find matrix of cofactors
        std::vector<std::vector<double>> cofactors{};

        for (int row = 0; row < m_matrix.size(); row++) {
            std::vector<double> cofactorRow{};
            for (int col = 0; col < m_matrix[row].size(); col++) {
                auto minor = cofactor(m_matrix, row, col);
                cofactorRow.push_back(pow(-1, row + col) * minor.calculateDeterminant());
            }
            cofactors.push_back(cofactorRow);
        }
        return Matrix(cofactors).transposeMain();
    }
}



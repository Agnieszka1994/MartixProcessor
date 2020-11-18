#include "MatrixClass.h"
#include <exception>
#include <cmath>

double Matrix::calculateDeterminant() const
{
    if (m_matrix.size() == 1) {
        return m_matrix[0][0];
    }
    
    if (m_matrix.size() == 2) {
        return m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1];
    }
    // initialize Sum to zero
    double running_sum{ 0 };
    // loop to traverse each column of matrix a
    for (size_t col = 0; col < m_matrix.size(); col++) {
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

Matrix Matrix::cofactor(std::vector<std::vector<double>> matrix, size_t rowIdx, size_t colIdx) const
{
	std::vector<std::vector<double>> newMatrix(matrix.size() - 1, std::vector<double>{});
	for (size_t row = 0; row < rowIdx; row++) {
		newMatrix[row].insert(newMatrix[row].end(), matrix[row].begin(), matrix[row].begin() + colIdx);
		newMatrix[row].insert(newMatrix[row].end(), matrix[row].begin() + colIdx + 1, matrix[row].end());
	}
	for (size_t row = rowIdx + 1; row < matrix.size(); row++) {
		newMatrix[row-1].insert(newMatrix[row-1].end(), matrix[row].begin(), matrix[row].begin() + colIdx);
		newMatrix[row-1].insert(newMatrix[row-1].end(), matrix[row].begin() + colIdx + 1, matrix[row].end());
	}
	return Matrix(newMatrix);
}

Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<std::vector<double>> matrix) : m_matrix{ matrix }
{
}


Matrix Matrix::operator+(const Matrix& other) const
{
    if (other.m_matrix.size() != m_matrix.size() || other.m_matrix[0].size() != m_matrix[0].size()) {
        std::invalid_argument error("The operation cannot be performed.");
        throw error;
    }
    Matrix sum;
    for (size_t i = 0; i < m_matrix.size(); i++) {
        std::vector<double> newRow{};
        for (size_t j = 0; j < m_matrix[0].size(); j++) {
            newRow.push_back(m_matrix[i][j] + other.m_matrix[i][j]);
        }
        sum.m_matrix.push_back(newRow);
    }
    return sum;
}

Matrix Matrix::operator+=(const Matrix& other)
{
    return Matrix();
}

std::ostream& operator<<(std::ostream& out, Matrix matrix)
{
    for (auto row : matrix.m_matrix) {
        for (auto ele : row) {
            out << ele << " ";
        }
        out << std::endl;
    }
    return out;
}

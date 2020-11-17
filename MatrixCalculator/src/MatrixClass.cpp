#include "MatrixClass.h"
#include <cmath>

double MatrixClass::calculateDeterminant(std::vector<std::vector<double>> helper)
{
    if (helper.size() == 1) {
        return helper[0][0];
    }
    
    if (helper.size() == 2) {
        return helper[0][0] * helper[1][1] - helper[1][0] * helper[0][1];
    }
    // initialize Sum to zero
    double running_sum{ 0 };
    // loop to traverse each column of matrix a
    for (int col = 0; col < helper.size(); col++) {
        // calculating the sign corresponding to co - factor of that sub matrix.
        double sign = std::pow(-1.0, col);

        // calling the function recursively to
        // get determinant value of a sub - matrix obtained
        double sub_determinant = calculateDeterminant(cofactor(helper, 0, col));
        // adding the calculated determinant to the total sum
        running_sum += (sign * helper[0][col] * sub_determinant);
    }
    return running_sum;
}

std::vector<std::vector<double>> MatrixClass::cofactor(std::vector<std::vector<double>> matrix, int rowIdx, int colIdx)
{
	std::vector<std::vector<double>> newMatrix(matrix.size() - 1, std::vector<double>{});
	for (int row = 0; row < rowIdx; row++) {
		newMatrix[row].insert(newMatrix[row].end(), matrix[row].begin(), matrix[row].begin() + colIdx);
		newMatrix[row].insert(newMatrix[row].end(), matrix[row].begin() + colIdx + 1, matrix[row].end());
	}
	for (int row = rowIdx + 1; row < matrix.size(); row++) {
		newMatrix[row-1].insert(newMatrix[row-1].end(), matrix[row].begin(), matrix[row].begin() + colIdx);
		newMatrix[row-1].insert(newMatrix[row-1].end(), matrix[row].begin() + colIdx + 1, matrix[row].end());
	}
	return newMatrix;
}

//return [row[: j] + row[j + 1:] for row in (matrix[: i] + matrix[i + 1:])]

//
//for (int i = 0; i < array.size(); i++) {
//	vector<int> newArray;
//	newArray.insert(newArray.end(), array.begin(), array.begin() + i);
//	newArray.insert(newArray.end(), array.begin() + i + 1, array.end());
//	vector<int> newPerm = currentPerm;
//
//	newPerm.push_back(array[i]);
//
//	constructPermutations(newArray, newPerm, solution);


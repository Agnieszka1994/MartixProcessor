#include <iostream>
#include "MatrixClass.h"
#include <iomanip>

int main() {

	MatrixClass a;
	a.m_matrix = {
		{ 0, 1, 0, 0, 0, 0, 0},
		{ 0, 1, 0, 0, 0, 0, 0},
		{ 0, 1, 0, 0, 0, 0, 0},
		{ 1, 1, 1, 1, 1, 1, 1},
		{ 0, 1, 0, 0, 0, 0, 0},
		{ 0, 1, 0, 0, 0, 0, 0},
		{ 0, 1, 0, 0, 0, 0, 0}
	};
	a.m_matrix = {
		{ 3, 1, 4, 4, 3, 2, 6},
		{ 5, 1, 6, 7, 0, 6, 6},
		{ 5, 1, 0, 6, 0, 89, 6},
		{ 1, 1, 1, 1, 1, 1, 1},
		{ 7, 8, 8, 67, 8, 89, 0},
		{ 7, 6, 7, 7, 89, 5, 34},
		{ 5, 87, 1, 12, 12, 2, 2}
	};
	for (auto row : a.m_matrix) {
		for (auto ele : row) {
			std::cout << ele << " ";
		}
		std::cout << std::endl;
	}

	std::vector<std::vector<double>> b = a.cofactor(a.m_matrix, 3, 1);

	for (auto row : b) {
		for (auto ele : row) {
			std::cout << ele << " ";
		}
		std::cout << std::endl;
	}

	double determ = a.calculateDeterminant(a.m_matrix);
	std::cout << std::fixed << std::setprecision(2) << determ << std::endl;;
}
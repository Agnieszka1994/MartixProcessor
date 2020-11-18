#include <iostream>
#include "MatrixClass.h"

int main() {

	std::vector<std::vector<double>> test{
		{ 3, 1, 4, 4, 3, 2, 6},
		{ 5, 1, 6, 7, 0, 6, 6},
		{ 5, 1, 0, 6, 0, 89, 6},
		{ 1, 1, 1, 1, 1, 1, 1},
		{ 7, 8, 8, 67, 8, 89, 0},
		{ 7, 6, 7, 7, 89, 5, 34},
		{ 5, 87, 1, 12, 12, 2, 2}
	};
	Matrix a(test);
	
	Matrix b({
		{ 3, 1, 4, 4, 3, 2, 6},
		{ 5, 1, 6, 7, 0, 6, 6},
		{ 5, 1, 0, 6, 0, 89, 6},
		{ 1, 1, 1, 1, 1, 1, 1},
		{ 7, 8, 8, 67, 8, 89, 0},
		{ 7, 6, 7, 7, 89, 5, 34},
		{ 5, 87, 1, 12, 12, 2, 2}
		});

	if (a.m_matrix.empty()) {
		std::cout << "empty vector!" << std::endl;
	}

	Matrix f = a + b;
	std::cout << a << std::endl;
	std::cout << f << std::endl;

}
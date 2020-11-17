#pragma once
#include <vector>
#include <iostream>

class MatrixClass
{
public:
	std::vector<std::vector<double>> m_matrix{};
	double i;

public:
	MatrixClass operator+(const std::vector<std::vector<double>>& other) const;
	MatrixClass operator+=(const std::vector<std::vector<double>>& other);
	MatrixClass operator*(const std::vector<std::vector<double>>& other) const;
	MatrixClass operator*(const double& other) const;

	friend std::ostream& operator <<(std::ostream& out, std::vector<std::vector<double>>& vec);
	friend std::istream& operator >>(std::istream& in, std::vector<std::vector<double>>& vec);

	void transposeMain();
	void transposeSide();
	void transposeVertical();
	void transposeHorizontal();

	double calculateDeterminant(std::vector<std::vector<double>> helper);
	std::vector<std::vector<double>> cofactor(std::vector<std::vector<double>> matrix, int rowIdx, int colIdx);
};


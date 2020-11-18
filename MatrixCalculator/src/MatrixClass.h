#pragma once
#include <vector>
#include <iostream>

class Matrix
{
public:
	
	Matrix();
	Matrix(std::vector<std::vector<double>> matrix);


public:
	Matrix operator+(const Matrix& other) const;
	Matrix operator+=(const Matrix& other);
	Matrix operator*(const Matrix& other) const;
	Matrix operator*(const double& scalar) const;
	std::vector <double>& operator[](const size_t& idx) const;

	Matrix transposeMain() const;
	Matrix transposeSide() const;
	Matrix transposeVertical() const;
	Matrix transposeHorizontal() const;
	Matrix inverse() const;
	double calculateDeterminant() const;

	friend std::ostream& operator <<(std::ostream& out, Matrix matrix);
	//friend std::istream& operator >>(std::istream& in, std::vector<std::vector<double>>& vec);

	std::vector<std::vector<double>> m_matrix{};
	Matrix cofactor(std::vector<std::vector<double>> matrix, size_t rowIdx, size_t colIdx) const;
};


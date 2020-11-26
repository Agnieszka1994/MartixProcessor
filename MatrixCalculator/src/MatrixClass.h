#pragma once
#include <vector>
#include <iostream>
namespace mtx 
{
	class Matrix
	{
	public:

		Matrix() = default;
		explicit Matrix(std::vector<std::vector<double>> matrix);

	public:

		Matrix operator+(const Matrix& other) const;
		Matrix operator-(const Matrix& other) const;
		Matrix operator*(const Matrix& other) const;
		Matrix operator*(const double& scalar) const;
		void operator+=(Matrix& other);
		void operator-=(Matrix& other);
		void operator*=(Matrix& other);
		void operator*=(double& scalar);
		void operator()(std::vector<std::vector<double>>&& vec);
		void operator()(const std::vector<std::vector<double>>& vec);
		std::vector <double>& operator[](const size_t& idx);

		Matrix transposeMain() const;
		Matrix transposeSide() const;
		Matrix transposeVertical() const;
		Matrix transposeHorizontal() const;
		Matrix inverse() const;
		double calculateDeterminant() const;
		bool squareMatrix() const;

		friend std::ostream& operator <<(std::ostream& out, const Matrix& matrix);	
		friend std::vector<std::vector<double>>& operator >>(std::vector<std::vector<double>>& vec, Matrix& matrix);

	private:
		std::vector<std::vector<double>> m_matrix{};
		Matrix cofactor(std::vector<std::vector<double>> matrix, size_t rowIdx, size_t colIdx) const;
	};
}



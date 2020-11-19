#pragma once
# include <vector>
# include <any>
# include <unordered_map>
# include <iostream>
# include "MatrixClass.h"


class Menu
{
public:
	void run();


private:

	static void DisplayMainMenu();
	static void DisplaySubMenu();
	void AddMatrices();
	void MultiplyMatrixByConstant();
	void MultiplyMatrices();
	void TransposeMatrix();
	void CalculateDeterminant();
	void InverseMatrix();
	void Exit();

private:
// menu options
	std::unordered_map<int, void (Menu::*)()> mainMenu{
		{1, &Menu::AddMatrices},
		{2, &Menu::MultiplyMatrixByConstant},
		{3, &Menu::MultiplyMatrices},
		{4, &Menu::TransposeMatrix},
		{5, &Menu::CalculateDeterminant},
		{6, &Menu::InverseMatrix},
		// temporary line for testing functions
		{0, &Menu::Exit} // target exit function
	};
	std::unordered_map<int, Matrix(Matrix::*)() const> transposeSubMenu{
		{1, &Matrix::transposeMain},
		{2, &Matrix::transposeSide},
		{3, &Matrix::transposeVertical},
		{4, &Matrix::transposeHorizontal}
	};

private: //input handler
	template<typename T>
	T getInput();
	template<typename T>
	std::vector<std::vector<T>> getMatrixFromInput(size_t rows, size_t columns);
	std::vector<size_t> getSizeFromInput();
};

template<typename T>
inline T Menu::getInput()
{
	T input;
	std::cin >> input;
	// error check
	while (std::cin.good() == false) {
		// clear stream
		std::cout << "Wrong input type! Please try again:" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		// get input again		
		std::cin >> input;
	}
	return input;
}

template<typename T>
inline std::vector<std::vector<T>> Menu::getMatrixFromInput(size_t rows, size_t columns)
{
	std::vector<std::vector<T>> matrix{};
	std::cout << "Enter matrix:" << std::endl;
	size_t assigned_rows{ 0 };

	while (rows > assigned_rows) {
		std::vector<T> currentRow(columns, 0);

		try {
			for (size_t i = 0; i < columns; i++) {
				currentRow[i] = getInput<T>();
			}
		}
		catch (std::exception&) {
			std::cout << "Something went wrong, please try again" << std::endl;
			return{ {} };
		}
		matrix.push_back(currentRow);
		assigned_rows++;
	}
	return matrix;
}


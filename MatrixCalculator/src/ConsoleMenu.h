#pragma once
# include <vector>
# include <unordered_map>
# include <iostream>
# include "MatrixClass.h"

namespace mtx
{
	extern const std::string ERROR_MSG;
	extern const std::string WRONG_INPUT;

	class Menu
	{
	public:
		void run();

	private:
		// display functions
		static void DisplayMainMenu();
		static void DisplaySubMenu();

		//matrix processing functions
		void AddMatrices();
		void MultiplyMatrixByConstant();
		void MultiplyMatrices();
		void TransposeMatrix();
		void CalculateDeterminant();
		void InverseMatrix();
		void Exit();

	private:
		// maps of function addresses for the main menu
		std::unordered_map<int, void (Menu::*)()> mainMenu{
			{1, &Menu::AddMatrices},
			{2, &Menu::MultiplyMatrixByConstant},
			{3, &Menu::MultiplyMatrices},
			{4, &Menu::TransposeMatrix},
			{5, &Menu::CalculateDeterminant},
			{6, &Menu::InverseMatrix},
			{0, &Menu::Exit}
		};
		// maps of function addresses for the transpose matrix SubMenu
		std::unordered_map<int, Matrix(Matrix::*)() const noexcept> transposeSubMenu{
			{1, &Matrix::transposeMain},
			{2, &Matrix::transposeSide},
			{3, &Matrix::transposeVertical},
			{4, &Matrix::transposeHorizontal}
		};

	private:
		//input handler functions
		template<typename T>
		static T getInput();
		template<typename T>
		static std::vector<std::vector<T>> getMatrixFromInput(size_t rows, size_t columns);
		static std::vector<size_t> getSizeFromInput();
	};

	template<typename T>
	inline T Menu::getInput()
	{
		T input;
		std::cin >> input;
		// error check
		while (std::cin.good() == false) {
			// clear stream
			std::cout << WRONG_INPUT << std::endl;
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
				std::cout << ERROR_MSG << std::endl;
				return{ {} };
			}
			matrix.push_back(currentRow);
			assigned_rows++;
		}
		return matrix;
	}
} // namespace mtx
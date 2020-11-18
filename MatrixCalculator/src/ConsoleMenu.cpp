#include "ConsoleMenu.h"

const std::string FIRST_INPUT{ "Enter size of first matrix:" };
const std::string SECOND_INPUT{ "Enter size of second matrix:" };
const std::string SINGLE_INPUT{ "Enter size of matrix:" };
const std::string CONST_INPUT{ "Enter constant:" };

void Menu::run()
{
	while (true) {
		system("cls");
		DisplayMainMenu();
		int choice = getInput<int>();
		try {
			(this->*mainMenu[choice])();
		}
		catch (...) {
			std::cout << "No such option available!" << std::endl;
		}
		system("pause");
	}
}

void Menu::DisplayMainMenu()
{
	// to be upgraded
	std::cout << "1. Add matrices" << std::endl;
	std::cout << "2. Multiply matrix by a constant" << std::endl;
	std::cout << "3. Multiply matrices" << std::endl;
	std::cout << "4. Transpose matrix" << std::endl;
	std::cout << "5. Calculate a determinant" << std::endl;
	std::cout << "6. Inverse matrix" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

void Menu::AddMatrices()
{
}

void Menu::MultiplyMatrixByConstant()
{
}

void Menu::MultiplyMatrices()
{
	std::cout << FIRST_INPUT << std::endl;
	std::vector<size_t> sizes = getSizeFromInput();
	Matrix a(getMatrixFromInput<double>(sizes[0], sizes[1]));
	std::cout << SECOND_INPUT << std::endl;
	std::vector<size_t> sizes_2 = getSizeFromInput();
	Matrix b(getMatrixFromInput<double>(sizes_2[0], sizes_2[1]));
	Matrix c = a * b;
	std::cout << c << std::endl;
}

void Menu::TransposeMatrix()
{
}

void Menu::CalculateDeterminant()
{
}

void Menu::InverseMatrix()
{
}

std::vector<size_t> Menu::getSizeFromInput()
{
	std::vector<size_t> sizes {0, 0};
	sizes[0] = getInput<size_t>();
	sizes[1] = getInput<size_t>();
	return sizes;
}

#include "ConsoleMenu.h"
#include "ConsoleClear.h"
#include <limits>

const std::string ERROR_MSG{ "Something went wrong! Please try again... " };
const std::string WRONG_INPUT{ "Wrong input type! Please try again:" };
const std::string FIRST_INPUT{ "Enter size of first matrix:" };
const std::string SECOND_INPUT{ "Enter size of second matrix:" };
const std::string SINGLE_INPUT{ "Enter size of matrix:" };
const std::string CONST_INPUT{ "Enter constant:" };
const std::string CHOICE_INPUT{ "Enter your choice:" };

void Menu::run()
{
	while (true) {
		Clear();
		DisplayMainMenu();
		std::cout << CHOICE_INPUT << std::endl;
		int choice = getInput<int>();
		if (mainMenu.find(choice) == mainMenu.end()) {
			std::cout << ERROR_MSG << std::endl;
			std::cin.clear();
			std::cin.get();
			continue;
		}
		try {
			(this->*mainMenu[choice])();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		std::cin.get();
	}
}

void Menu::TransposeMatrix()
{
	DisplaySubMenu();
	std::cout << CHOICE_INPUT << std::endl;
	int choice = getInput<int>();
	if (!choice) {
		return;
	}
	Matrix a;
	try {

		std::cout << SINGLE_INPUT << std::endl;
		std::vector<size_t> sizes = getSizeFromInput();
		Matrix b(getMatrixFromInput<double>(sizes[0], sizes[1]));

		a = (b.*transposeSubMenu[choice])();
	}
	catch (...) {
		std::cout << ERROR_MSG << std::endl;
		return;
	}
	std::cout << std:: endl << a << std::endl;
	//std::cin.get();
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
	std::cout << "0. Exit" << std::endl;
}

void Menu::DisplaySubMenu()
{
	std::cout << "1. Main diagonal" << std::endl;
	std::cout << "2. Side diagonal" << std::endl;
	std::cout << "3. Vertical line" << std::endl;
	std::cout << "4. Horizontal line" << std::endl;
	std::cout << "0. Back to main menu" << std::endl;
}

void Menu::AddMatrices()
{
	std::cout << FIRST_INPUT << std::endl;
	std::vector<size_t> sizes = getSizeFromInput();
	Matrix a(getMatrixFromInput<double>(sizes[0], sizes[1]));
	std::cout << SECOND_INPUT << std::endl;
	std::vector<size_t> sizes_2 = getSizeFromInput();
	Matrix b(getMatrixFromInput<double>(sizes_2[0], sizes_2[1]));
	Matrix c;
	try {
		c = a + b;
	}
	catch (std::invalid_argument e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << std::endl << c << std::endl;
}

void Menu::MultiplyMatrixByConstant()
{
	Matrix a;
	double scalar;
	try {
		std::cout << SINGLE_INPUT << std::endl;
		std::vector<size_t> sizes = getSizeFromInput();
		a(getMatrixFromInput<double>(sizes[0], sizes[1]));
		std::cout << CONST_INPUT << std::endl;
		scalar = getInput<double>();
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << std::endl << a * scalar << std::endl;
}

void Menu::MultiplyMatrices()
{
	std::cout << FIRST_INPUT << std::endl;
	std::vector<size_t> sizes = getSizeFromInput();
	Matrix a(getMatrixFromInput<double>(sizes[0], sizes[1]));
	std::cout << SECOND_INPUT << std::endl;
	std::vector<size_t> sizes_2 = getSizeFromInput();
	Matrix b(getMatrixFromInput<double>(sizes_2[0], sizes_2[1]));
	Matrix c;
	try {
		c = a * b;
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << std::endl << c << std::endl;
}



void Menu::CalculateDeterminant()
{
	Matrix a;
	double determinant;
	try {
		std::cout << SINGLE_INPUT << std::endl;
		std::vector<size_t> sizes = getSizeFromInput();
		a(getMatrixFromInput<double>(sizes[0], sizes[1]));
		determinant = a.calculateDeterminant();
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << std::endl << "Determinant: " << determinant << std::endl;
}

void Menu::InverseMatrix()
{
	Matrix a;
	try {
		std::cout << SINGLE_INPUT << std::endl;
		std::vector<size_t> sizes = getSizeFromInput();
		a = Matrix(getMatrixFromInput<double>(sizes[0], sizes[1])).inverse();
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << std::endl << a << std::endl;
}

void Menu::Exit()
{
	std::cout << "Bye! :)" << std::endl;
	exit(0);
}

std::vector<size_t> Menu::getSizeFromInput()
{
	std::vector<size_t> sizes {0, 0};
	sizes[0] = getInput<size_t>();
	sizes[1] = getInput<size_t>();
	return sizes;
}

#include "ConsoleMenu.h"


void Menu::run()
{
	while (true) {
		int choice = getInput<int>();
		try {
			mainMenu[choice];
		}
		catch (...) {
			std::cout << "No such option available!" << std::endl;
		}
	}
}

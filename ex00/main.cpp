#include "Bureaucrat.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

int main(void) {
PRINT("============== CONSTRUCTOR == START ==============");

	Bureaucrat guy;
	std::cout << '\t' << guy << "\n\n";


	Bureaucrat newGuy(guy);
	std::cout << '\t' << newGuy << "\n\n";

	try {
		newGuy.demoteGrade();
	} catch (std::exception & e) {
		std::cerr << "EXCEPTION CAUGHT:\n\t";
		std::cerr << e.what() << std::endl;
	}
PRINT("\n\n");
PRINT("============== PROMOTION == START ==============");
	Bureaucrat newestGuy = Bureaucrat("Pierce", 150);

	std::cout << newestGuy;
	for (int i = 0; i < 150; i++) {
		try {
			newestGuy.promoteGrade();
			std::cout << newestGuy;
		} catch (std::exception & e) {
			std::cerr << "EXCEPTION CAUGHT:\n\t";
			std::cerr << e.what() << std::endl;
		}
	}
PRINT("\n\n");
PRINT("============== DEMOTION == START ==============");

	std::cout << newestGuy;
	for (int i = 0; i < 150; i++) {
		try {
			newestGuy.demoteGrade();
			std::cout << newestGuy;
		} catch (std::exception & e) {
			std::cerr << "EXCEPTION CAUGHT:\n\t";
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}


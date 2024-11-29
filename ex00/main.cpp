#include "Bureaucrat.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

int main(void) {
PRINT("============== TEST == START ==============");

PRINT("FIELD: Constructors");
	Bureaucrat newGuy;
	std::cout << newGuy;

	return 0;
}


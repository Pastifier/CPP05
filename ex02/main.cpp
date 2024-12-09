#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	std::cout << "Hello, world!" << std::endl;

	Bureaucrat ahmed("Ahmed", 1);
	ShrubberyCreationForm brush;
	ahmed.signForm(brush);
	ahmed.executeForm(brush);
	return 0;
}


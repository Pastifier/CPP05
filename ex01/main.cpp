//#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

int main(void) {
PRINT("============== FORM == START ==============");
PRINT("\n");

	Bureaucrat ahmed("Ahmed", 150);
	Bureaucrat emran("Emran", 25);

	Form visa("Visa Form", 50, 25);

PRINT("============== EXCEPTION == START ==============");

	try {
		Form myForm("Bad Form", 1, -500);
	} catch (std::exception & e) {
		std::cerr << "EXCEPTION CAUGHT while trying to initialize form\n";
		std::cerr << e.what() << std::endl;
	}
PRINT("\n");
	try {
		Form myForm("Another Bad Form", 156, 1);
	} catch (std::exception & e) {
		std::cerr << "EXCEPTION CAUGHT while trying to initialize form\n";
		std::cerr << e.what() << std::endl;
	}

PRINT("\n");
PRINT("============== SIGNATURE == START ==============");
	std::cout << visa << std::endl;
	for (int i = 1; i < 150; i++) {
		ahmed.signForm(visa);
		ahmed.promoteGrade();
	}
PRINT("\n");
	emran.signForm(visa);
PRINT("\n");
	return 0;
}

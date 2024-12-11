#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define PRINT(X) std::cout << X << std::endl

void testShrubbery() {
PRINT("* TESTING SHRUBBERY *");
	Bureaucrat ahmed("Ahmed", 1);
	ShrubberyCreationForm brush("falafel");

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush);
		ahmed.executeForm(brush);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
	ShrubberyCreationForm brush2(brush);

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush2);
		ahmed.executeForm(brush2);
		if (ahmed.getGrade() != 1)
			ahmed.promoteGrade();
	}
	ShrubberyCreationForm brush3 = brush;

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush3);
		ahmed.executeForm(brush3);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
}

void testRobotomy() {
PRINT("* TESTING ROBOTOMY *");
	Bureaucrat ahmed("Ahmed", 1);
	RobotomyRequestForm brush("falafel");

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush);
		ahmed.executeForm(brush);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
	RobotomyRequestForm brush2(brush);

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush2);
		ahmed.executeForm(brush2);
		if (ahmed.getGrade() != 1)
			ahmed.promoteGrade();
	}
}

void testPresidential() {
PRINT("* TESTING PRESIDENTIAL *");
	Bureaucrat ahmed("Ahmed", 1);
	AForm* brush = new PresidentialPardonForm("falafel");

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(*brush);
		ahmed.executeForm(*brush);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
	PresidentialPardonForm brush2(*(PresidentialPardonForm *)brush);

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush2);
		ahmed.executeForm(brush2);
		if (ahmed.getGrade() != 1)
			ahmed.promoteGrade();
	}
	delete brush;
}

int main(void) {
	//testShrubbery();
	//testRobotomy();
	testPresidential();
	return 0;
}

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define PRINT(X) std::cout << X << std::endl

void testShrubbery() {
PRINT("* TESTING SHRUBBERY *");
	Intern someRandomIntern;
	Bureaucrat ahmed("Ahmed", 1);
	AForm* brush = someRandomIntern.makeForm("Shrubbery Creation", "falafel");

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(*brush);
		ahmed.executeForm(*brush);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
	ShrubberyCreationForm brush2(*(ShrubberyCreationForm *)brush);

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush2);
		ahmed.executeForm(brush2);
		if (ahmed.getGrade() != 1)
			ahmed.promoteGrade();
	}
	ShrubberyCreationForm brush3 = *(ShrubberyCreationForm *)brush;

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush3);
		ahmed.executeForm(brush3);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
}

void testRobotomy() {
PRINT("* TESTING ROBOTOMY *");
	Intern someRandomIntern;
	Bureaucrat ahmed("Ahmed", 1);
	AForm* brush = someRandomIntern.makeForm("Robotomy Request", "Marvin");

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(*brush);
		ahmed.executeForm(*brush);
		if (ahmed.getGrade() != 150)
			ahmed.demoteGrade();
	}
	RobotomyRequestForm brush2(*(RobotomyRequestForm *)brush);

	for (int i = 0; i <= 149; i++) {
		ahmed.signForm(brush2);
		ahmed.executeForm(brush2);
		if (ahmed.getGrade() != 1)
			ahmed.promoteGrade();
	}
}

void testPresidential() {
PRINT("* TESTING PRESIDENTIAL *");
	Intern someRandomIntern;
	Bureaucrat ahmed("Ahmed", 1);
	AForm* brush = someRandomIntern.makeForm("Presidential Pardon", "Deepthought");

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
	testShrubbery();
	//testRobotomy();
	//testPresidential();
	return 0;
}

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(
		"Shrubbery Creation",
		145,
		137
	)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
	: AForm(
		"Shrubbery Creation",
		145,
		137
	)
{ this->_isSigned = other.getSignatureStat(); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getSignatureStat();
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
	if (!this->_isSigned) throw ShrubberyCreationForm::FormNotSignedException(_name);
	if (executor.getGrade() >= _execGrade) throw ShrubberyCreationForm::GradeTooLowException(executor.getName());
	try {
		std::fstream file(executor.getName() + "_shrubbery");
		file << "         * \n";
		file << "        /|\\ \n";
		file << "       /*|O\\ \n";
		file << "      /*/|*\\*\\ \n";
		file << "     /X/O|*\\X\\ \n";
		file << "    /*/X/|\\X\\*\\ \n";
		file << "   /O/*/X|*\\O\\X\\ \n";
		file << "  /*/O/X/|\\X\\O\\*\\ \n";
		file << " /X/O/*/X|O\\X\\*\\O\\ \n";
		file << "/O/X/*/O/|\\X\\*\\O\\X\\ \n";
		file << "        |X| \n";
		file << "        |X| \n";
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
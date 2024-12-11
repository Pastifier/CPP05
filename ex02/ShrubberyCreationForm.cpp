#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(
		"Shrubbery Creation",
		145,
		137
	),
	_target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target_)
	: AForm(
		"Shrubbery Creation",
		145,
		137
	),
	_target(target_)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
	: AForm(
		"Shrubbery Creation",
		145,
		137
	),
	_target(other.getTarget())
{ this->_isSigned = other.getSignatureStat(); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getSignatureStat();
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string const& ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->_isSigned) throw ShrubberyCreationForm::FormNotSignedException(_name);
	if (executor.getGrade() > _execGrade) throw ShrubberyCreationForm::GradeTooLowException(_name);

	try
	{
		std::fstream file((this->getTarget() + "_shrubbery").c_str(), std::ios::out);

		if (!file.is_open())
		{
			std::cerr << this->getName() << ": Error opening file for writing." << std::endl;
			return;
		}

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

		file.close();

		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

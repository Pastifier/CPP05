#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _grade(150), _name("Bob") {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const & other) {
	this->_grade = other.getGrade();
	this->_name = other.getName();
}

Bureaucrat::Bureaucrat(std::string const& name_, int grade_) {
	this->_grade = grade_;
	checkGradeValidity();

	this->_name = name_;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
		this->_name = rhs.getName();
	}
	return *this;
}


std::string const& Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::checkGradeValidity() {
	if (_grade < 1)
		throw GradeTooHighException(_name);
	else if (_grade > 150)
		throw GradeTooLowException(_name);
}

void Bureaucrat::promoteGrade() {
	_grade--;
	checkGradeValidity();
}

void Bureaucrat::demoteGrade() {
	_grade++;
	checkGradeValidity();
}


Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const & name_)
	: _message("Grade too high for Bureaucrat: " + name_) {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const & name_)
	: _message("Grade too low for Bureaucrat: " + name_) {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return _message.c_str();
}


std::ostream& operator<<(std::ostream &o, Bureaucrat *inst) {
	o << inst->getName() << ", bureaucrat grade " << inst->getGrade() << std::endl;
	return o;
}

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Bob"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const & other) {
	this->_grade = other.getGrade();
	this->_name = other.getName();
}

Bureaucrat::Bureaucrat(std::string const& name_, int grade_)
	: _name(name_), _grade(grade_) {
	checkGradeValidity();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
		this->_name = rhs.getName();
	}
	return *this;
}

void Bureaucrat::signForm(AForm& form_) {
	try {
		std::cout << this->_name << " tries to sign " << form_.getName() << "\n";
		form_.beSigned(*this);
		std::cout << "Success!" << std::endl;
	} catch (std::exception& e) {
		std::cout << "EXCEPTION CAUGHT!\n" << _name << " couldn't sign form: ";
		std::cout << e.what() << std::endl;
	}
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
	if (_grade == 1)
		throw GradeTooHighException(_name);
	_grade--;
}

void Bureaucrat::demoteGrade() {
	if (_grade == 150)
		throw GradeTooLowException(_name);
	_grade++;
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

#if defined(__MACH__)
Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
#else
Bureaucrat::GradeTooHighException::~GradeTooHighException() _GLIBCXX_NOTHROW {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() _GLIBCXX_NOTHROW {}
#endif


std::ostream& operator<<(std::ostream& o, Bureaucrat const & inst) {
	o << inst.getName() << ", bureaucrat grade " << inst.getGrade() << "." << std::endl;
	return o;
}

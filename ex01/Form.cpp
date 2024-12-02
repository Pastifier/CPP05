#include "Form.hpp"

Form::Form()
	: _name("Residence Visa"),
	_isSigned(false),
	_signGrade(150),
	_execGrade(150) {}

Form::Form(std::string const &name_, int signGrade_, int execGrade_)
	: _name(name_),
	_isSigned(false),
	_signGrade(signGrade_),
	_execGrade(execGrade_)
{
	checkGradeValidity();
}

Form::~Form() {}

Form::Form(Form const & other)
	: _name(other.getName()),
	_isSigned(other.getSignatureStat()),
	_signGrade(other.getSignGrade()),
	_execGrade(other.getExecGrade()) {}

Form& Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getSignatureStat();
	}
	return *this;
}

void Form::beSigned(Bureaucrat const & signatory) {
	if (signatory.getGrade() <= _signGrade)
	{
		_isSigned = true;
		return;
	}
	throw GradeTooLowException(_name);
}

std::string const& Form::getName() const {
	return this->_name;
}

bool Form::getSignatureStat() const {
	return this->_isSigned;
}

int Form::getSignGrade() const {
	return this->_signGrade;
}

int Form::getExecGrade() const {
	return this->_execGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
	return _message.c_str();
}
Form::GradeTooHighException::GradeTooHighException(std::string const & name_)
	: _message(name_ + ": Grade too high") {}

const char* Form::GradeTooLowException::what() const throw() {
	return _message.c_str();
}
Form::GradeTooLowException::GradeTooLowException(std::string const & name_)
	: _message(name_ + ": Grade too low.") {}

void Form::checkGradeValidity() {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException(_name);
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException(_name);
}

#if defined(__MACH__)
Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
#else
Form::GradeTooHighException::~GradeTooHighException() _GLIBCXX_NOTHROW {}
Form::GradeTooLowException::~GradeTooLowException() _GLIBCXX_NOTHROW {}
#endif

std::ostream& operator<<(std::ostream& o, Form const & inst) {
	o << "==========================================================\n";
	o << "Form Name: " << inst.getName() << "\n";
	o << "Signature Status: " << (inst.getSignatureStat() ? "signed\n" : "not signed yet\n");
	o << "Sign Grade Requirement: " << inst.getSignGrade() << "\n";
	o << "Execution Grade Requirement: " << inst.getExecGrade() << "\n";
	o << "==========================================================" << std::endl;
	return o;
}

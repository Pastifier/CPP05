#include "AForm.hpp"

AForm::AForm()
	: _name("Residence Visa"),
	_isSigned(false),
	_signGrade(150),
	_execGrade(150) {}

AForm::AForm(std::string const &name_, int signGrade_, int execGrade_)
	: _name(name_),
	_isSigned(false),
	_signGrade(signGrade_),
	_execGrade(execGrade_)
{
	checkGradeValidity();
}

AForm::~AForm() {}

AForm::AForm(AForm const & other)
	: _name(other.getName()),
	_isSigned(other.getSignatureStat()),
	_signGrade(other.getSignGrade()),
	_execGrade(other.getExecGrade()) {}

AForm& AForm::operator=(AForm const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getSignatureStat();
	}
	return *this;
}

void AForm::beSigned(Bureaucrat const & signatory) {
	if (signatory.getGrade() <= _signGrade)
	{
		_isSigned = true;
		return;
	}
	throw GradeTooLowException(_name);
}

std::string const& AForm::getName() const {
	return this->_name;
}

bool AForm::getSignatureStat() const {
	return this->_isSigned;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

int AForm::getExecGrade() const {
	return this->_execGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return _message.c_str();
}
AForm::GradeTooHighException::GradeTooHighException(std::string const & name_)
	: _message(name_ + ": Grade too high") {}

const char* AForm::GradeTooLowException::what() const throw() {
	return _message.c_str();
}
AForm::GradeTooLowException::GradeTooLowException(std::string const & name_)
	: _message(name_ + ": Grade too low.") {}

void AForm::checkGradeValidity() {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException(_name);
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException(_name);
}

#if defined(__MACH__)
AForm::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
AForm::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
#else
AForm::GradeTooHighException::~GradeTooHighException() _GLIBCXX_NOTHROW {}
AForm::GradeTooLowException::~GradeTooLowException() _GLIBCXX_NOTHROW {}
#endif

std::ostream& operator<<(std::ostream& o, AForm const & inst) {
	o << "==========================================================\n";
	o << "Form Name: " << inst.getName() << "\n";
	o << "Signature Status: " << (inst.getSignatureStat() ? "signed\n" : "not signed yet\n");
	o << "Sign Grade Requirement: " << inst.getSignGrade() << "\n";
	o << "Execution Grade Requirement: " << inst.getExecGrade() << "\n";
	o << "==========================================================" << std::endl;
	return o;
}

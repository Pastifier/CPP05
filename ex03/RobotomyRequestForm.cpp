#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(
		"Robotomy Request",
		72,
		45
	),
	_target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target_)
	: AForm(
		"Robotomy Request",
		72,
		45
	),
	_target(target_)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
	: AForm(
		"Robotomy Request",
		72,
		45
	),
	_target(other.getTarget())
{ this->_isSigned = other.getSignatureStat(); }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getSignatureStat();
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string const& RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	static short alt;

	if (!this->getSignatureStat()) throw RobotomyRequestForm::FormNotSignedException(_name);
	if (executor.getGrade() > this->getExecGrade()) throw RobotomyRequestForm::GradeTooLowException(_name);

	std::cout << "* drilling noises *" << std::endl;
	if (alt++ % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	alt = (2 == alt) ? 0 : alt; // YODA!!!!
}


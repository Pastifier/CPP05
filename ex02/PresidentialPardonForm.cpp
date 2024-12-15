#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(
		"Presidential Pardon",
		25,
		5
	),
	_target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target_)
	: AForm(
		"Presidential Pardon",
		25,
		5
	),
	_target(target_)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
	: AForm(
		"Presidential Pardon",
		25,
		5
	),
	_target(other.getTarget())
{ this->_isSigned = other.getSignatureStat(); }

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
		this->_isSigned = rhs.getSignatureStat();
	}
	return *this;
}

std::string const& PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->_isSigned) throw PresidentialPardonForm::FormNotSignedException(this->_name);
	if (executor.getGrade() > this->_execGrade) throw PresidentialPardonForm::GradeTooLowException(this->_name);

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

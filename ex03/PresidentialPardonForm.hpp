#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string const& target_);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & other);
	PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

	std::string const& getTarget() const;

	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
	PresidentialPardonForm();
};

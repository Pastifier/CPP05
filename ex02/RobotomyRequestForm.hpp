#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string const& target_);
	RobotomyRequestForm(RobotomyRequestForm const & other);
	RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

	std::string const& getTarget() const;

	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
};

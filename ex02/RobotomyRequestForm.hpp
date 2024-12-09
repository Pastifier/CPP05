#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & other);
	RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

	std::string const& getTarget() const;

	void execute(Bureaucrat const & executor);
private:
	std::string _target;
};

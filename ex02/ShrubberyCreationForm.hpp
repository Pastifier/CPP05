#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & other);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);
	void execute(Bureaucrat const & executor) const;
};

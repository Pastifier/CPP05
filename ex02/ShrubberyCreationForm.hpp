#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & other);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

	std::string const& getTarget() const;

	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
};

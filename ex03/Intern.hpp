#include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(Intern const & other);
	Intern& operator=(Intern const & rhs);

	AForm* makeForm(std::string const& formName, std::string const& formTarget);
};
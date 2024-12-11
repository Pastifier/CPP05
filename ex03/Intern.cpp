#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const & other) { (void)other; }
Intern& Intern::operator=(Intern const & rhs) { (void)rhs; return *this; }

static inline AForm	*createShrubbery(const std::string target) { return new ShrubberyCreationForm(target); }
static inline AForm	*createRobotomy(const std::string target) { return new RobotomyRequestForm(target); }
static inline AForm	*createPresident(const std::string target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(std::string const& formName, std::string const& formTarget) {
	AForm* ret;

	AForm* (* const formMakers[3])(std::string const) = {
		&createShrubbery,
		&createRobotomy,
		&createPresident
	};
	std::string const keys[3] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (formName == keys[i]) {
			try {
				ret = (formMakers)[i](formTarget);
				std::cout << "Intern creates " << keys[i] << std::endl;
				return ret;
			} catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	std::cerr << "Intern wasn't trained to create form of type `" << formName << "'" << std::endl;
	return NULL;
}

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const &other) { (void)other; }
Intern &Intern::operator=(Intern const &rhs) {
  (void)rhs;
  return *this;
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &formTarget) {

  std::string const keys[3] = {"Shrubbery Creation", "Robotomy Request",
                               "Presidential Pardon"};

  int i = 0;
  while (i < 3) {
    if (keys[i] == formName)
      break;
    ++i;
  }

  try {
    switch (i) {
    case 0:
      return new ShrubberyCreationForm(formTarget);
      break;
    case 1:
      return new RobotomyRequestForm(formTarget);
      break;
    case 2:
      return new PresidentialPardonForm(formTarget);
    default:
      break;
    }
  } catch (std::bad_alloc &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cerr << "Intern wasn't trained to create form of type `" << formName
            << "'" << std::endl;
  return NULL;
}

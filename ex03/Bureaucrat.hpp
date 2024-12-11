#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & other);
	Bureaucrat& operator=(Bureaucrat const & rhs);
	Bureaucrat(std::string const& name_, int grade_);

	std::string const& getName() const;
	int getGrade() const;

	void promoteGrade();
	void demoteGrade();

	void signForm(AForm& form_);
	void executeForm(AForm const & form);

private:
	std::string _name;
	int _grade;
	void checkGradeValidity();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
#if defined(__MACH__)
		virtual ~GradeTooHighException() _NOEXCEPT;
#else
		virtual ~GradeTooHighException() _GLIBCXX_NOTHROW;
#endif
		GradeTooHighException(std::string const & name_);
	private:
		GradeTooHighException& operator=(GradeTooHighException const & rhs);
		std::string _message;
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
#if defined(__MACH__)
		virtual ~GradeTooLowException() _NOEXCEPT;
#else
		virtual ~GradeTooLowException() _GLIBCXX_NOTHROW;
#endif
		GradeTooLowException(std::string const & name_);
	private:
		GradeTooLowException& operator=(GradeTooLowException const & rhs);
		std::string _message;
	};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & inst);
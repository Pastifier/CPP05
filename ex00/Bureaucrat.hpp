#pragma once

#include <string>
#include <exception>
#include <iostream>

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

private:
	std::string _name;
	int _grade;
	void checkGradeValidity();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
		virtual ~GradeTooHighException() _NOEXCEPT;
		GradeTooHighException(std::string const & name_);
	private:
		GradeTooHighException& operator=(GradeTooHighException const & rhs);
		std::string _message;
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
		virtual ~GradeTooLowException() _NOEXCEPT;
		GradeTooLowException(std::string const & name_);
	private:
		GradeTooLowException& operator=(GradeTooLowException const & rhs);
		std::string _message;
	};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & inst);
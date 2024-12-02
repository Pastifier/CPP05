#pragma once

#include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	Form(std::string const &name_, int signGrade_, int execGrade_);
	~Form();
	Form(Form const & other);
	Form& operator=(Form const & rhs);

	std::string const& getName() const;
	bool getSignatureStat() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat const & signatory);

private:
	std::string const _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

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
	void checkGradeValidity();
};

std::ostream& operator<<(std::ostream& o, Form const & inst);

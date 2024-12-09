#include "Bureaucrat.hpp"

class AForm
{
public:
	AForm();
	AForm(std::string const &name_, int signGrade_, int execGrade_);
	AForm(AForm const & other);
	AForm& operator=(AForm const & rhs);

	std::string const& getName() const;
	bool getSignatureStat() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat const & signatory);

	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual ~AForm();

protected:
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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
#if defined(__MACH__)
		virtual ~FormNotSignedException() _NOEXCEPT;
#else
		virtual ~FormNotSignedException() _GLIBCXX_NOTHROW;
#endif
		FormNotSignedException(std::string const & name_);
	private:
		FormNotSignedException& operator=(FormNotSignedException const & rhs);
		std::string _message;
	};
	void checkGradeValidity();
};

std::ostream& operator<<(std::ostream& o, const AForm const & inst);
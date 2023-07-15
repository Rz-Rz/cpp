#include <string>
#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class AForm
{
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
    virtual	~AForm();
		AForm &operator=(const AForm &copy);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(Bureaucrat &bureaucrat);
    virtual void  execute(Bureaucrat const & executor) const = 0;  

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);
#endif

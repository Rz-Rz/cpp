#include <string>
#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class Form
{
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &copy);
		virtual ~Form();
		Form &operator=(const Form &copy);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);
#endif

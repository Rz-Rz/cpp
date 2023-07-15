#include <string>
#include "AForm.hpp"

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		void	execute(Bureaucrat const &executor) const;

		std::string	getTarget() const;

		class RobotomizationFailureException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string	_target;
};
#endif

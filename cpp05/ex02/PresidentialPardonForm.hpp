#include <string>
#include "Form.hpp"

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		void	execute(Bureaucrat const &executor) const;

		std::string	getTarget() const;

		class PresidentialPardonException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string	_target;


};

#endif

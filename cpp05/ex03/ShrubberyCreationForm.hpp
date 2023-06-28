#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		std::string getTarget(void) const;
		void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};
#endif

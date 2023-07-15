#include <string>
#include "AForm.hpp"

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();
		Intern &operator=(const Intern &copy);

		AForm *makeForm(std::string formName, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		typedef struct s_formList
		{
			std::string formName;
			AForm *formType;
		} FormCreator;
};
#endif

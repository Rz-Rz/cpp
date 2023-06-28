#include <string>
#include "Form.hpp"

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();
		Intern &operator=(const Intern &copy);

		Form *makeForm(std::string formName, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		typedef struct s_formList
		{
			std::string formName;
			Form *formType;
		} FormCreator;
};
#endif

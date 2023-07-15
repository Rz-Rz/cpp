#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern() {
	return;
}

Intern::Intern(const Intern &copy) {
	*this = copy;
	return;
}

Intern::~Intern() {
	return;
}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	FormCreator formList[] = {

		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"", NULL}
	};
	AForm *resultForm = NULL;

	for (int i = 0; formList[i].formType != NULL; i++)
	{
		if (formList[i].formName == formName)
			resultForm = formList[i].formType;
		else
			delete formList[i].formType;
	}
	if (resultForm == NULL)
		throw Intern::FormNotFoundException();
	return resultForm;
};

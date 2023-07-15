#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	Intern intern;
  Bureaucrat John("John", 1);
	AForm *form;

	try {
		form = intern.makeForm("robotomy request", "target1");
    John.signForm(*form);
    John.executeForm(*form);
		delete form; // Clean up the form after usage.
	} catch (Intern::FormNotFoundException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		form = intern.makeForm("presidential pardon", "target2");
		delete form; // Clean up the form after usage.
	} catch (Intern::FormNotFoundException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		form = intern.makeForm("shrubbery creation", "target3");
		delete form; // Clean up the form after usage.
	} catch (Intern::FormNotFoundException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		form = intern.makeForm("unknown form", "target4");
		delete form; // Clean up the form after usage.
	} catch (Intern::FormNotFoundException &e) {
		std::cerr << "Caught expected exception for unknown form: " << e.what() << std::endl;
	}
    return 0;
}

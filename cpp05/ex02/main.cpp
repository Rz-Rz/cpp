#include "Bureaucrat.hpp"
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	srand(time(NULL)); // Initialize random seed
	try {
		Bureaucrat john("John", 1); // Create a bureaucrat named John with grade 1
		RobotomyRequestForm form("Alice"); // Create a robotomy request form for Alice

		std::cout << "Form before signing:\n" << form << std::endl;

		john.signForm(form); // John signs the form

		std::cout << "Form after signing:\n" << form << std::endl;

		john.executeForm(form); // John executes the form
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 50); // Create a bureaucrat named Alice with grade 50
		RobotomyRequestForm form("John"); // Create a robotomy request form for John

		std::cout << "Form before signing:\n" << form << std::endl;

		alice.signForm(form);

		std::cout << "Form after signing:\n" << form << std::endl;

		form.execute(alice); // Alice tries to execute the form, should fail because her grade is too low
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}

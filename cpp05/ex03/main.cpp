#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{

	/* Bureaucrat b1("Bureaucrat1", 150);  // Lowest grade */
	/* Bureaucrat b2("Bureaucrat2", 1);    // Highest grade */

	/* ShrubberyCreationForm s1("Home"); */
	/* ShrubberyCreationForm s2("Office"); */

	/* std::cout << b1 << std::endl; */
	/* std::cout << b2 << std::endl; */
	/* std::cout << s1 << std::endl; */
	/* std::cout << s2 << std::endl; */

	/* try { */
	/* 	// Testing the execution with an unsigned form */
	/* 	std::cout << "Testing execution with unsigned form:\n"; */
	/* 	b1.signForm(s1); */
	/* 	s1.execute(b1); */
	/* } */
	/* catch (std::exception &e) { */
	/* 	std::cerr << "Error: " << e.what() << std::endl; */
	/* } */

	/* try { */
	/* 	// Testing the execution with a form signed by a bureaucrat with a too low grade */
	/* 	std::cout << "Testing execution with a form signed by a bureaucrat with a too low grade:\n"; */
	/* 	b1.signForm(s2); */
	/* 	s2.execute(b1); */
	/* } */
	/* catch (std::exception &e) { */
	/* 	std::cerr << "Error: " << e.what() << std::endl; */
	/* } */
	/* try { */
	/* 	// Testing the execution with a correctly signed form */
	/* 	std::cout << "Testing execution with correctly signed form:\n"; */
	/* 	b2.signForm(s1); */
	/* 	s1.execute(b2); */
	/* } */
	/* catch (std::exception &e) { */
	/* 	std::cerr << "Error: " << e.what() << std::endl; */
	/* } */

	/* try { */
	/* 	Bureaucrat bob("Bob", 1); // Create a bureaucrat named Bob with grade 1 */
	/* 	PresidentialPardonForm form("Alice"); // Create a presidential pardon form for Alice */

	/* 	std::cout << "Form before signing:\n" << form << std::endl; */

	/* 	bob.signForm(form); // Bob signs the form */

	/* 	std::cout << "Form after signing:\n" << form << std::endl; */

	/* 	form.execute(bob); // Bob executes the form */
	/* } catch (std::exception &e) { */
	/* 	std::cout << e.what() << std::endl; */
	/* } */
	/* try { */
	/* 	Bureaucrat alice("Alice", 50); // Create a bureaucrat named Alice with grade 50 */
	/* 	PresidentialPardonForm form("Bob"); // Create a presidential pardon form for Bob */

	/* 	std::cout << "Form before signing:\n" << form << std::endl; */

	/* 	alice.signForm(form); // Alice tries to sign the form, should fail because her grade is too low */

	/* 	std::cout << "Form after signing:\n" << form << std::endl; */

	/* 	form.execute(alice); // Alice tries to execute the form, should fail because her grade is too low */
	/* } catch (std::exception &e) { */
	/* 	std::cout << e.what() << std::endl; */
	/* } */

	/* srand(time(NULL)); // Initialize random seed */

	/* try { */
	/* 	Bureaucrat john("John", 1); // Create a bureaucrat named John with grade 1 */
	/* 	RobotomyRequestForm form("Alice"); // Create a robotomy request form for Alice */

	/* 	std::cout << "Form before signing:\n" << form << std::endl; */

	/* 	john.signForm(form); // John signs the form */

	/* 	std::cout << "Form after signing:\n" << form << std::endl; */

	/* 	form.execute(john); // John executes the form */
	/* } catch (std::exception &e) { */
	/* 	std::cout << e.what() << std::endl; */
	/* } */

	/* try { */
	/* 	Bureaucrat alice("Alice", 50); // Create a bureaucrat named Alice with grade 50 */
	/* 	RobotomyRequestForm form("John"); // Create a robotomy request form for John */

	/* 	std::cout << "Form before signing:\n" << form << std::endl; */

	/* 	alice.signForm(form); // Alice tries to sign the form, should fail because her grade is too low */

	/* 	std::cout << "Form after signing:\n" << form << std::endl; */

	/* 	form.execute(alice); // Alice tries to execute the form, should fail because her grade is too low */
	/* } catch (std::exception &e) { */
	/* 	std::cout << e.what() << std::endl; */
	/* } */
	Intern intern;
	Form *form;

	try {
		form = intern.makeForm("robotomy request", "target1");
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

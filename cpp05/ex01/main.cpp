#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    /* try */
    /* { */
    /*     Bureaucrat bureaucrat("John Doe", 0); */
    /* } */
    /* catch (std::exception &e) */
    /* { */
    /*     std::cout << "Exception caught: " << e.what() << std::endl; */
    /* } */

    /* try */
    /* { */
    /*     Bureaucrat bureaucrat("John Doe", 151); */
    /* } */
    /* catch (std::exception &e) */
    /* { */
    /*     std::cout << "Exception caught: " << e.what() << std::endl; */
    /* } */

    /* try */
    /* { */
    /*     Bureaucrat bureaucrat("John Doe", 1); */
    /*     std::cout << bureaucrat << std::endl; */
    /*     bureaucrat.incrementGrade(); */
    /* } */
    /* catch (std::exception &e) */
    /* { */
    /*     std::cout << "Exception caught: " << e.what() << std::endl; */
    /* } */

    /* try */
    /* { */
    /*     Bureaucrat bureaucrat("John Doe", 150); */
    /*     std::cout << bureaucrat << std::endl; */
    /*     bureaucrat.decrementGrade(); */
    /* } */
    /* catch (std::exception &e) */
    /* { */
    /*     std::cout << "Exception caught: " << e.what() << std::endl; */
    /* } */

    /* Bureaucrat bureaucrat("John Doe", 75); */
    /* std::cout << bureaucrat << std::endl; */

    /* Bureaucrat copy = bureaucrat; */
    /* std::cout << copy << std::endl; */

	try {
		Bureaucrat bob("Bob", 50);
		Form form1("Form1", 40, 30);
		std::cout << bob << std::endl;
		std::cout << form1 << std::endl;
		bob.signForm(form1);
		std::cout << form1 << std::endl;

		Bureaucrat alice("Alice", 35);
		std::cout << alice << std::endl;
		alice.signForm(form1);
		std::cout << form1 << std::endl;

		Form form2("Form2", 30, 25);
		std::cout << form2 << std::endl;
		alice.signForm(form2);
		std::cout << form2 << std::endl;

		Form form3("Form3", 30, 30);
		form3.beSigned(alice);
	}
	catch(std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

    return 0;
}

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat bureaucrat("John Doe", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureaucrat("John Doe", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureaucrat("John Doe", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureaucrat("John Doe", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Bureaucrat bureaucrat("John Doe", 75);
    std::cout << bureaucrat << std::endl;

    Bureaucrat copy = bureaucrat;
    std::cout << copy << std::endl;

    return 0;
}

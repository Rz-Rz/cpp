#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy.getTarget())
{
	return;
}

std::string RobotomyRequestForm::getTarget() const {
	return (_target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy.getTarget();
	}
	return (*this);
}

const char *RobotomyRequestForm::RobotomizationFailureException::what() const throw()
{
	return ("Robotomization failed");
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		throw RobotomizationFailureException();
}

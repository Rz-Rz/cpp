#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), _target(copy.getTarget())
{
	return;
}

std::string PresidentialPardonForm::getTarget() const {
	return (_target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		Form::operator=(copy);
		_target = copy.getTarget();
	}
	return (*this);
}

const char *PresidentialPardonForm::PresidentialPardonException::what() const throw()
{
	return ("Presidential pardon failed");
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	if (!getSigned())
		throw Form::FormNotSignedException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw AForm::GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	*this = copy;
}

AForm & AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		_signed = copy.getSigned();
	}
	std::cout << "Name and grades are const and can't be overwritten, only _signed was copied" << std::endl;
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{

	return (_gradeToExecute);
}

bool AForm::getSigned() const
{
	return (_signed);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
  else
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
  out << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed, grade to sign is " << form.getGradeToSign() << ", grade to execute is " << form.getGradeToExecute();
	return (out);
}

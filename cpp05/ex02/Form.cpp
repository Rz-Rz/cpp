#include "Form.hpp"
#include <iostream>

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	*this = copy;
}

Form & Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		_signed = copy.getSigned();
	}
	std::cout << "Name and grades are const and can't be overwritten, only _signed was copied" << std::endl;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (_name);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool Form::getSigned() const
{
	return (_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute" << std::endl;
	return (out);
}

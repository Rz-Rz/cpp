#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
}

Form::Form(const Form &copy)
{
	*this = copy;
}

Form & Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_signed = copy._signed;
	}
	return (*this);
}

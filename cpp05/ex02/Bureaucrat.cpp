#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1 || grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->name = name;
	this->grade = grade;
}


Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	this->name = other.name;
	this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
	this->name = other.name;
	this->grade = other.grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

void Bureaucrat::executeForm(AForm const & form)
{
  try
  {
    form.execute(*this);
    std::cout << this->getName() << " executes " << form.getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cout << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

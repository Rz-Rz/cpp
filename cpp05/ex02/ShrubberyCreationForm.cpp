#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src.getTarget()) {
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
	ofs << "      /\\      " << std::endl;
	ofs << "     /\\*\\     " << std::endl;
	ofs << "    /\\O\\*\\    " << std::endl;
	ofs << "   /*/\\/\\/\\   " << std::endl;
	ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
	ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << std::endl;
	return;
}

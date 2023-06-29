#include "ScalarConverter.hpp"
#include <iostream>

void ScalarConvert::convert(std::string const &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
	{
		handleFloatPseudoLiteral(literal);
	}
}

void ScalarConvert::handleFloatPseudoLiteral(std::string const &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
	return;
}


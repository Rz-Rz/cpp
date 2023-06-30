#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

void ScalarConvert::convert(std::string const &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "+inf" || literal == "-inf" )
		handleInfPseudoLiteral(literal);
	else if (literal == "nanf" || literal == "nan")
		handleNanPseudoLiteral(literal);
	else
		handleNumericLiteral(literal);
}

void ScalarConvert::handleInfPseudoLiteral(std::string const &literal)
{
	double dinf;
	float finf;
	if (literal.find("-") != std::string::npos)
{
		dinf = -std::numeric_limits<double>::infinity();
		finf = -std::numeric_limits<float>::infinity();
	}
	else
	{
		dinf = std::numeric_limits<double>::infinity();
		finf = std::numeric_limits<float>::infinity();
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << finf << "f" << std::endl;
	std::cout << "double: " << dinf << std::endl;
	return;
}

void ScalarConvert::handleNanPseudoLiteral(std::string const &literal)
{
	double dnan;
	float fnan;
	(void)literal;
	dnan = std::numeric_limits<double>::quiet_NaN();
	fnan = std::numeric_limits<float>::quiet_NaN();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << fnan << "f" << std::endl;
	std::cout << "double: " << dnan << std::endl;
	return;

}

void ScalarConvert::handleNumericLiteral(std::string const &literal)
{
	if (literal.find('.') != std::string::npos)
	{
		if (literal.find('f') != std::string::npos)
			handleFloatLiteral(literal);
		else
			handleDoubleLiteral(literal);
	}
	else if (literal.find('\'') != std::string::npos)
		handleCharLiteral(literal);
	/* else */
	/* 	handleIntLiteral(literal); */
}

int coundtDecimalPlaces(const std::string &s)
{
	std::size_t decimalPos = s.find('.');
	if (decimalPos == std::string::npos)
		return (0);
	return (s.size() - decimalPos - 1);
}

void ScalarConvert::handleFloatLiteral(std::string const &literal)
{
	float f;
	double d;
	std::stringstream ss;
	int decimalPlace;
	

	ss << literal;
	ss >> f;
	decimalPlace = countDecimalPlaces(literal);


	d = static_cast<double>(f);
	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		if (std::isprint(static_cast<char>(f)))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(decimalPlace) << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
	return;
}

void ScalarConvert::handleDoubleLiteral(std::string const &literal)
{
	double d;
	std::stringstream ss;
	ss << literal;
	ss >> d;
	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		if (std::isprint(static_cast<char>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10 + 1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return;
}

void ScalarConvert::handleCharLiteral(std::string const &literal)
{
	int i;
	float f;
	double d;
	char c;
	std::string literalWithoutQuotes;

	for (size_t i = 0; i < literal.size(); ++i) 
	{
		if (literal[i] != '\'') {
			literalWithoutQuotes += literal[i];
		}
	}
	std::stringstream ss(literalWithoutQuotes);
	ss >> i;
	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		if (std::isprint(static_cast<char>(i)))
		{
			c = static_cast<char>(i);
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(i);
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10 + 1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return;
}

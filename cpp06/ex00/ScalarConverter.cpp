#include "ScalarConverter.hpp"
#include "cmath"
#include <iostream>
#include <iomanip>
#include <cerrno>

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

bool ScalarConvert::validateInput(std::string const &literal)
{
	 std::string valid_chars = ".f+-0123456789";
	 size_t f_pos = literal.find_first_of('f');

	 if (literal.find_first_not_of(valid_chars) != std::string::npos)
		 return false;
	 if (f_pos != std::string::npos && f_pos != literal.size() - 1)
		 return false;
	 return true;
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

int ScalarConvert::countDecimalPlaces(const std::string &s)
{
	std::size_t decimalPos = s.find('.');
	if (decimalPos == std::string::npos)
		return (0);
	return (s.size() - decimalPos - 2);
}

int ScalarConvert::getPrecision(const std::string &literal)
{
	std::size_t decimal_pos = literal.find('.');
	std::size_t decimal_digits = 0;
	if (decimal_pos != std::string::npos)
	{
		decimal_digits = literal.size() - decimal_pos - 1; // -2 to exclude the decimal point and 'f'
		char last_char = literal[literal.size() - 1];
		if (last_char == 'f') // if the literal ends with 'f', subtract one more
		{
			--decimal_digits;
		}
	}
	return (decimal_digits);
}

void ScalarConvert::handleFloatLiteral(std::string const &literal)
{
	float f;
	double d;
	std::stringstream ss;
	char* end;
	
	/* std::cout << "HERE\n" << std::endl; */
	f = static_cast<float>(std::strtof(literal.c_str(), &end));
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
	
	if ((f == std::numeric_limits<float>::max() || f == -std::numeric_limits<float>::max()) && errno == ERANGE )
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(getPrecision(literal)) << f << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(d) << std::endl;
	std::cout << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
	return;
}

void ScalarConvert::handleDoubleLiteral(std::string const &literal)
{
	double d;
	std::stringstream ss;
	char* end;

	errno = 0;
	d = static_cast<double>(std::strtod(literal.c_str(), &end));
	if (errno == ERANGE)
	{
		printCharOverflow();
		printIntOverflow();
		printFloatOverflow();
		printDoubleOverflow();
		errno = 0;
	}
	else {
		if (floatOverflow(d))
		{
			printCharOverflow();
			printIntOverflow();
			printFloatOverflow();
			printDouble(d, literal);
		}
	}
		
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
	printDouble(d, literal);
	std::cout << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
	return;
}

void ScalarConvert::handleCharLiteral(std::string const &literal)
{
	int i = 0;
	float f;
	double d;
	char c;
	char *end;
	std::string literalWithoutQuotes;

	for (size_t i = 0; i < literal.size(); ++i) 
	{
		if (literal[i] != '\'') {
			literalWithoutQuotes += literal[i];
		}
	}
	d = static_cast<double>(std::strtol(literalWithoutQuotes.c_str(), &end, 10));
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
	std::cout << "float: " << f << ".0f" << std::endl;
	printDouble(d, literal);
	return;
}

void ScalarConvert::printDouble(double d, std::string const &literal)
{
	if (std::isinf(d))
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (getPrecision(literal) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
	{
		std::cout << "double: " << std::fixed << std::setprecision(getPrecision(literal)) << d << std::endl;
		std::cout << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
	}
}

void ScalarConvert::printFloat(double d, std::string const &literal)
{
	float f;
	if (std::numeric_limits<float>::max() < d || std::numeric_limits<float>::min() > d)
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	else
	{
		f = static_cast<float>(d);
		if (getPrecision(literal) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(getPrecision(literal)) << f << "f" << std::endl;
			std::cout << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
		}
	}
}

void printDoubleOverflow()
{
	std::cout << "double: impossible" << std::endl;
}
void printFloatOverflow()
{
	std::cout << "float: impossible" << std::endl;
}

void printIntOverflow()
{
	std::cout << "int: impossible" << std::endl;
}

void printCharOverflow()
{
	std::cout << "char: impossible" << std::endl;
}

bool floatOverflow(double d)
{
	if (std::numeric_limits<float>::max() < d || std::numeric_limits<float>::min() > d)
		return true;
	return false;
}

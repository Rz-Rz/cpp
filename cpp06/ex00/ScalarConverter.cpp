#include "ScalarConverter.hpp"
#include <iostream>

ScalarConvert::ScalarConvert(std::string str) : _str(str) {
	return;
}

ScalarConvert::~ScalarConvert() {
	return;
}

ScalarConvert::ScalarConvert(ScalarConvert const &other) {
	*this = other;
}

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &other) {
	if (this != &other) {
		this->_str = other._str;
	}
	return *this;
}

bool is_literal(std::string const &input)
{
	std::string literals[6] = {"nan", "nanf", "-inf", "+inf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++)
	{
		if (input == literals[i])
		{
			return true;
		}
	}
	return false;
}

void ScalarConvert::convert(std::string const &input)
{
	is_literal(input);
}


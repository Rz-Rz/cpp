#include "ScalarConverter.hpp"

int main()
{
	/* ScalarConvert::convert("nanf"); */
	/* ScalarConvert::convert("nan"); */
	/* ScalarConvert::convert("+inf"); */
	/* ScalarConvert::convert("-inf"); */
	/* ScalarConvert::convert("+inff"); */
	/* ScalarConvert::convert("-inff"); */

	ScalarConvert::convert("0.0f");
	ScalarConvert::convert("127.6661f");
	ScalarConvert::convert("127.0001f");

	ScalarConvert::convert("42.0f"); // 0
	return (0);
}

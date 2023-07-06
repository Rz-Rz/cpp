#include "ScalarConverter.hpp"

/* int main() */
/* { */
	/* ScalarConvert::convert(".f"); */
	/* ScalarConvert::convert("...f"); */
	/* ScalarConvert::convert("f"); */
	/* ScalarConvert::convert("fffff"); */
	/* ScalarConvert::convert(""); */
	/* ScalarConvert::convert("f11f"); */
	/* ScalarConvert::convert("a"); */
	/* ScalarConvert::convert("nanf"); */
	/* ScalarConvert::convert("nan"); */
	/* ScalarConvert::convert("+inf"); */
	/* ScalarConvert::convert("-inf"); */
	/* ScalarConvert::convert("+inff"); */
	/* ScalarConvert::convert("-inff"); */

	/* ScalarConvert::convert("0.0f"); */
	/* ScalarConvert::convert("127.6661f"); */
	/* ScalarConvert::convert("127.0001f"); */
	/* ScalarConvert::convert("42.0f"); // */ 
	/* ScalarConvert::convert("133788888888888.1337f"); */
	/* ScalarConvert::convert("133788888888888.1337999999999999999999999999999999999999999999999f"); */
	/* ScalarConvert::convert("13378888888999999999999999999999999999999999999999999999999999999999999999999999999999998888.1337999999999999999999999999999999999999999999999f"); */
									 //
	/* ScalarConvert::convert("42.0"); */
	/* ScalarConvert::convert("1337.1337"); */
	/* ScalarConvert::convert("9999999.9"); */
	/* ScalarConvert::convert("99999999.9"); */
	/* ScalarConvert::convert("99999997.9"); */
	/* ScalarConvert::convert("99999990.9"); */
	/* ScalarConvert::convert("999999909.9"); */
	/* ScalarConvert::convert("9999999099.9"); */
	/* ScalarConvert::convert("99999990999999.9"); */
	/* ScalarConvert::convert("9999999099999999.9"); */
	/* ScalarConvert::convert("99999990999999999.9"); */
	/* ScalarConvert::convert("999999909999999999.9"); */
	/* ScalarConvert::convert("9999999099999999999.9"); */
	/* ScalarConvert::convert("999999909999999999999.9"); */
	/* ScalarConvert::convert("99999990999999999999999.9"); */
	/* ScalarConvert::convert("9999999099999999999999999.9"); */
	/* ScalarConvert::convert("999999909999999999999999999.9"); */
	/* ScalarConvert::convert("99999990999999999999999999999.9"); */
	/* ScalarConvert::convert("9999999099999999999999999999999.9"); */
	/* ScalarConvert::convert("99999990999999999999999999999999999999999.9"); */
	/* ScalarConvert::convert("9999999999999909999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.9"); */
 	/* ScalarConvert::convert("1"); */
 	/* ScalarConvert::convert("'1'"); */
	/* ScalarConvert::convert("'54'"); */
	/* ScalarConvert::convert("'54.0'"); */
	/* ScalarConvert::convert("'54.0f'"); */
	/* ScalarConvert::convert("'29'"); */
	/* ScalarConvert::convert("'33'"); */
	/* ScalarConvert::convert("33'"); */
	/* return (0); */
/* } */
int main(int argc, char* argv[])
{
    if (argc != 2) // Check if the number of arguments is correct
    {
        std::cerr << "Usage: " << argv[0] << " <string to convert>" << std::endl;
        return 1;
    }
	ScalarConvert::convert(argv[1]);
    return 0;
}

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConvert {
	public:
		ScalarConvert();
		static void convert(std::string const &input);

		class NonDisplayableException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		ScalarConvert(std::string str);
		~ScalarConvert();
		ScalarConvert(ScalarConvert const &other);
		static void handleInfPseudoLiteral(std::string const &literal);
		static void handleNanPseudoLiteral(std::string const &literal);
		static void handleNumericLiteral(std::string const &literal);
		static void handleFloatLiteral(std::string const &literal);
		static void handleDoubleLiteral(std::string const &literal);
		static void handleCharLiteral(std::string const &literal);
		static void handleIntLiteral(std::string const &literal);
		static int countDecimalPlaces(const std::string &s);
		static bool validateInput(std::string const &literal);
		static int getPrecision(std::string const &literal);
		static void printChar(double d);
		static void printInt(double d);
		static void printFloat(double d, std::string const &literal);
		static void printDouble(double d, std::string const &literal);
		static void printDoubleOverflow();
		static void printIntOverflow();
		static void printCharOverflow();
		static void printFloatOverflow();
		static bool floatOverflow(double d);
		static bool checkTwoQuotes(std::string const &literal);
		static bool atLeastOneNum(std::string const &literal);
};


#endif

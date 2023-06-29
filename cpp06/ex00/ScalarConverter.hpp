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
		static void handleFloatPseudoLiteral(std::string const &literal);

};


#endif

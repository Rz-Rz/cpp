#include <iostream>
#include <string>
#include <cctype>

//Function to convert a string to uppercase
std::string to_uppercase(const std::string &s)
{
	std::string result;
		for (size_t i = 0; i < s.length(); i++)
		{
			result += toupper(s[i]);
		}
		return (result);
}

int main(int argc, char *argv[])
{
	std::string input;
	if (argc == 1)
	{
		input = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << input << std::endl;
		return (0);
	}
	else
	{
		for ( int i = 1; i < argc; i++ )
		{
			input = to_uppercase(argv[i]);
			std::cout << input;
		}
			return (0);
	}
	return (0);
}

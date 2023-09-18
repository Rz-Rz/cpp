#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int ac, char **argv) {
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc [filename]\n";
		return 0;
	}
	BitcoinExchange exchange("data.csv");
	exchange.load_csv();
	exchange.load_psv(argv[1]);
	return 0;
}

#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **argv) {
	(void)ac;
	BitcoinExchange exchange("data.csv");
	exchange.load_csv();
	exchange.load_psv(argv[1]);
	return 0;
}

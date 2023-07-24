#include "BitcoinExchange.hpp"
#include <fstream>

int main() {
  BitcoinExchange exchange("data.csv");
  exchange.load_csv();
  exchange.load_psv("bitcoin.txt");
  return 0;
}

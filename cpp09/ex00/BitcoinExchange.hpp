#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
  public:
    BitcoinExchange(const std::string& filename);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
    bool load_csv();
    bool load_psv(std::string filename);
    float getValue(const std::string& date);
    void printDataset();
    void printPsv();
    bool isValidDateFormat(const std::string& date);
    std::string trim(const std::string& str);


  private:
	BitcoinExchange();
    std::string filename;
    std::multimap<std::string, float> csv_data;
    std::multimap<std::string, float> psv_data;
    bool validate(const std::string& date, float value);
};


#endif

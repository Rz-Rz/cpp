#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& filename);
    bool load();
    float getValue(const std::string& date);
    void printAll();

private:
    std::string filename;
    std::map<std::string, float> data;
    bool validate(const std::string& date, float value);
};

#endif // BITCOINEXCHANGE_HPP

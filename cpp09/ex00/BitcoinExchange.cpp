#include "BitcoinExchange.hpp"
#include <ctime>
#include <climits>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

BitcoinExchange::BitcoinExchange(const std::string& filename) : filename(filename) {}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : filename(other.filename), csv_data(other.csv_data), psv_data(other.psv_data) {}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::load_psv(std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file) {
    std::cerr << "Error: Could not open file " << filename << "\n";
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string udate;
    std::string date;
    float value;


    // Skip whitespace before the pipe character
    std::getline(ss >> std::ws, udate, '|');
    date = trim(udate);

    // Skip whitespace after the pipe character
    if (!(ss >> std::ws >> value)) {
      std::cerr << "Error: Invalid line format: ";
      std::cerr << "line: " << line << "\n";
      continue;
    }

    if (!validate(date, value)) {
      std::cerr << "Error: Invalid data: ";
      std::cerr << "line: " << line << "\n";
      continue;
    }

    // std::cout << getValue(date) << "\n";
    std::cout << "Date: " << date << ", Value: " << std::fixed << std::setprecision(2) << getValue(date) * value << "\n";
    // psv_data.insert(std::make_pair(date, value));
  }

  return true;
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) {
  if (date.size() != 10) {
    return false;
  }
  if (date < "2009-01-02") {
    return false;
  }
  for (size_t i = 0; i < date.size(); ++i) {
    if (i == 4 || i == 7) {
      if (date[i] != '-') {
        return false;
      }
    } else {
      if (!isdigit(date[i])) {
        return false;
      }
    }
  }
  return true;
}

bool BitcoinExchange::validate(const std::string& date, float value) {
    return isValidDateFormat(date) && value >= 0 && value <= 1000;
}


bool BitcoinExchange::load_csv() {
  std::ifstream file(filename.c_str());
  if (!file) {
    std::cerr << "Error: Could not open file " << filename << "\n";
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date;
    float value;

    if (!(std::getline(ss, date, ',') && ss >> value)) {
      std::cerr << "Error: Invalid line format: ";
      std::cerr << "line: " << line << "\n";
      continue;
    }

    csv_data.insert(std::make_pair(date, value));
  }

  return true;
}

float BitcoinExchange::getValue(const std::string& date) {
  std::multimap<std::string, float>::iterator it = csv_data.lower_bound(date);

  // If the date is not found and it is not the first element, get the previous date
  if (it == csv_data.end() || it->first != date) {
    if (it == csv_data.begin()) {
      // There is no lower date
      return it->second;
    } else {
      --it;  // Move to the previous date
    }
  }
  return it->second;  // Return the first value associated with the found date
}

void BitcoinExchange::printDataset() {
    for (std::map<std::string, float>::const_iterator it = csv_data.begin(); it != csv_data.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << "\n";
    }
}

void BitcoinExchange::printPsv() {
    for (std::multimap<std::string, float>::const_iterator it = psv_data.begin(); it != psv_data.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << "\n";
    }
}

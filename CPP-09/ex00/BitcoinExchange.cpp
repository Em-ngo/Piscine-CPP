#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &csvFile) {
    loadBitcoinPrices(csvFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadBitcoinPrices(const std::string &csvFile) {
    std::ifstream file(csvFile.c_str());  
    if (!file.is_open()) {
        std::cerr << "Error: could not open CSV file." << std::endl;
        exit(1);
    }

    std::string line;
    getline(file, line); 

    while (getline(file, line)) {
        std::stringstream ss(line); 
        std::string date, priceStr;
        
   
        getline(ss, date, ',');
        getline(ss, priceStr);

        if (date.empty() || priceStr.empty()) {
            std::cerr << "Error: invalid CSV line => " << line << std::endl;
            continue;
        }
        
        double price = atof(priceStr.c_str()); 
        bitcoinPrices[date] = price;
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string &inputFile) const {
    std::ifstream file(inputFile.c_str()); 
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        exit(1);
    }

    std::string line;
    getline(file, line); 

    while (getline(file, line)) {
        std::stringstream ss(line);  
        std::string date, valueStr;
        
        
        getline(ss, date, '|');
        getline(ss, valueStr);


        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);


        if (date.empty() || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value = atof(valueStr.c_str());  
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double btcPrice = getBitcoinValue(date);
        if (btcPrice == -1) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * btcPrice) << std::endl;
    }

    file.close();
}

double BitcoinExchange::getBitcoinValue(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = bitcoinPrices.lower_bound(date);
    

    if (it != bitcoinPrices.end() && it->first == date)
        return it->second;

    if (it != bitcoinPrices.begin())
        return (--it)->second;

    return -1; 
}

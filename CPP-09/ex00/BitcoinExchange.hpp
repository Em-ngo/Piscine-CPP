#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream> 
#include <sstream> 
#include <cstdlib> 
#include <map>


class BitcoinExchange {
private:
    std::map<std::string, double> bitcoinPrices;

public:
    BitcoinExchange(const std::string &csvFile);
    ~BitcoinExchange();

    void loadBitcoinPrices(const std::string &csvFile);
    void processInputFile(const std::string &inputFile) const;
    double getBitcoinValue(const std::string &date) const;
};

#endif

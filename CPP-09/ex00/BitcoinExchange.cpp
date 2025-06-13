#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange&BitcoinExchange::operator=(BitcoinExchange const &) {
    return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &) {}


BitcoinExchange::BitcoinExchange(const std::string &csvFile) {
    loadBitcoinPrices(csvFile);
}

BitcoinExchange::~BitcoinExchange() {}

bool isValidDateFormat(const std::string &date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    return true;
}

bool isRealDate(const std::string &date) {
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // Année bissextile
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

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

    std::string header;
    if (!getline(file, header)) {
        std::cerr << "Error: empty input file." << std::endl;
        exit(1);
    }

    header.erase(0, header.find_first_not_of(" \t"));
    header.erase(header.find_last_not_of(" \t") + 1);

    if (header != "date | value") {
        std::cerr << "Error: invalid header. Expected 'date | value' but got '" << header << "'." << std::endl;
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

        if (date.empty() || valueStr.empty() || !isValidDateFormat(date) ||
        !isRealDate(date)) {
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

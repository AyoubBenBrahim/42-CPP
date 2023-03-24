#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>

const double MAX_BTC_VALUE = 1000.0;
const double MIN_BTC_VALUE = 0;

# define RESET			"\033[0m"
# define GREEN			"\033[32m"

class BitcoinExchange
{
private:
	// std::string ....;

public:
	BitcoinExchange(void);
	
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange(void);

void parseFile(std::string, char, std::map<std::string, double> &);
bool isValidDate(std::string&);
double toDouble(std::string , bool );
	// std::string getBitcoinExchangeName(void) const;
	// void setBitcoinExchangeName(std::string const &_name);
	
};

#endif
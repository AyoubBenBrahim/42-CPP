#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    char delimiter;
    if (ac != 2)
    {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    std::map<std::string, double> database;

    delimiter = ',';
    btc.parseFile("data.csv", delimiter, database);
    delimiter = '|';
    btc.parseFile(av[1], delimiter, database);

    return 0;
}
#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
#include <limits>
#include <cmath>
#include <iostream>
#include <float.h> 
#include <iomanip>

class Conversion
{
private:
    std::string input;

    bool        _isChar;
    bool        _isInt;
    bool        _isFloat;
    bool        _isDouble;
    bool        _isPseudoLiteral;

    char        charHolder;
	long        intHolder;
	double       floatHolder;
	double      doubleHolder;

public:
    Conversion();
    ~Conversion();
    Conversion(const std::string input);
    Conversion(const Conversion &);

    Conversion  &operator=(const Conversion &);
    void        isPrintable(std::string input);
    void        isInt(std::string input);
    void        isFloat(std::string input);
    void        isDouble(std::string input);
    void        isPseudoLiteral(std::string input);

    void        toChar();
    void        toInt();
    void        toFloat();
    void        toDouble();

    void        printOrchestration();
    void        printPseudoLiteral();

    void        charHandler();
    void        intergerHandler();
    void        floatHandler();
    void        doubleHandler();

    void        printer();
};

#endif
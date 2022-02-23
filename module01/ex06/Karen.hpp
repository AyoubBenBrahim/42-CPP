#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>
#include <iostream>

enum LEVEL
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    SHUT_UP
};

LEVEL hash(std::string const &level);

class Karen
{
public:
    Karen(void);
    ~Karen(void);
    void complain(std::string level);
    void ptrToMemberFunc(Karen *pKaren, void (Karen::*pfn)(void));

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif

/*

A member pointer is a different type category from a ordinary pointer. 
The member pointer will have to be used together with an object of its class

// take the addr of a member atrribute
*/

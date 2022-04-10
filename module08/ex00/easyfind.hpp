#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <algorithm>
#include <iostream>

class MyExceptions : public std::runtime_error
{
public:
    MyExceptions(int nbr, const std::string &error) : std::runtime_error(error.c_str())
    {
        std::cerr << "\tErr: {" << nbr << "}";
    }
};

template <typename T>
void easyfind(T &container, int intToFind)
{
    typename T::iterator itr;
    itr = std::find(container.begin(), container.end(), intToFind);
    try
    {
        if (itr == container.end())
           throw MyExceptions(intToFind," NotFound.");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
    std::cout << "\tFound: " << *itr << std::endl;
}

#endif
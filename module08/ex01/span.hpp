#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>

#define RESET "\033[0m"
#define RED "\033[31m"

class MyExceptions : public std::runtime_error
{
public:
    MyExceptions(const std::string &error) : std::runtime_error(error.c_str())
    {
    }
};

class Span
{
private:
    std::multiset<int> container;
    unsigned int capacity;

public:
    Span();
    ~Span();
    Span(unsigned int);
    Span(Span const &);
    Span &operator=(Span const &span);

    void    addNumber(int);
    void	addNumber(std::multiset<int>::iterator begin, std::multiset<int>::iterator end);
    int		shortestSpan(void);
    int		longestSpan(void);
};

#endif


#include "span.hpp"

Span::Span(void) : capacity(0) {}

Span::Span(unsigned int N) : capacity(N) {}

Span::~Span(void)
{
    container.clear();
}

Span::Span(Span const &copy)
{
    *this = copy;
}

Span &Span::operator=(Span const &rhs)
{
    if (this == &rhs)
        return (*this);

    this->capacity = rhs.capacity;
    this->container = rhs.container;
    return (*this);
}

void Span::addNumber(int num)
{
    if (this->container.size() >= this->capacity)
        throw MyExceptions(" FullSpanException.\n");
    
    this->container.insert(num);
}

void Span::addNumber(std::multiset<int>::iterator begin, std::multiset<int>::iterator end)
{
    try
    {
        this->container.insert(begin, end);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int Span::shortestSpan(void)
{
    int shortest;

    if (this->container.empty())
        throw MyExceptions(" EmptySpan.\n");
    if (this->container.size() == 1)
        throw MyExceptions(" NoSpanFound.\n");

    std::multiset<int>::iterator cur = container.begin();
    std::multiset<int>::iterator next = ++container.begin();

    shortest = *next - *cur;

    for (; next != container.end(); next++)
    {
        if (*next - *cur < shortest)
            shortest = *next - *cur;
        cur++;
    }

    return (shortest);
}

int Span::longestSpan(void)
{
    if (this->container.empty())
        throw MyExceptions(" EmptySpan.\n");
    if (this->container.size() == 1)
        throw MyExceptions(" NoSpanToFind.\n");
    
    return (*container.rbegin() - *container.begin());
}
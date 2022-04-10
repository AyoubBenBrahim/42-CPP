#include "span.hpp"

void print(Span sp)
{
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n";
}

int main()
{
    {
         std::cout << "\n **** FULL SPAN ****" << "\n\n";
        try
        {
            Span sp = Span(5);
            sp.addNumber(50);
            sp.addNumber(39);
            sp.addNumber(7);
            sp.addNumber(6);
            sp.addNumber(11);
            sp.addNumber(44);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << e.what() << RESET << "\n";
        }
    }

    
    {
        std::cout << " **** EMPTY SPAN ****" << "\n\n";
        Span sp = Span(80);
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << e.what() << RESET << "\n";
        }

        std::cout << " ****  ONE VALUE SPAN ****" << "\n\n";
        sp.addNumber(13);

        try
        {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << e.what() << RESET << "\n";
        }
    }

    {
        std::cout << " **** NORMAL SPAN ****" << "\n\n";
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(-85);
        sp.addNumber(11);

       print(sp);
    }

    {
        std::cout << " **** SPAN WITH NEGATIVE/POSITIVE VALUES  ****" << "\n\n";
        Span sp = Span(5);
        sp.addNumber(7);
        sp.addNumber(-6);
        sp.addNumber(144);
        sp.addNumber(-8);

        print(sp);
    }

    {
        std::cout << " ****  SPAN WITH RANGE ****" << "\n\n";

        std::multiset<int> mySet;

        for (int i = 0; i < 10000; ++i)
        {
            if (i < 3333)
                mySet.insert(i + 99);
            if (i >= 3333 && i < 6666)
                mySet.insert(i * -99);
            if (i >= 6666)
                mySet.insert(i * 99);
        }

        Span sp = Span(10000);
        sp.addNumber(mySet.begin(), mySet.end());
        print(sp);
    }
}
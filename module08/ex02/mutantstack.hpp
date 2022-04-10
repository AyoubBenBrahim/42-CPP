
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack(){};
    virtual ~MutantStack(){};
    MutantStack(MutantStack const *mut) : std::stack<T, Container>(mut) {}

    MutantStack &operator=(MutantStack const &rhs)
    {
        if (this == &rhs)
            return *this;

        std::stack<T, Container>::operator=(rhs);
        return *this;
    }

    typedef typename Container::iterator iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_iterator const_iterator;
    

    iterator begin() { return this->c .begin(); }
    iterator end() { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_iterator cbegin() { return this->c.cbegin(); }
    const_iterator cend() { return this->c.cend(); }
};

#endif

/*
The purpose of having const_iterator over iterator is to manage the accessesibility of the container on which the respective iterator runs. 
*/
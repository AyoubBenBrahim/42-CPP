#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>
#include <iomanip>

#define RESET "\033[0m"
#define RED "\033[31m"

class MyExceptions : public std::runtime_error
{
public:
    MyExceptions(const std::string &error) : std::runtime_error(error.c_str())
    {
    }
};

template <class T>
class Array
{
private:
    T *array;
    unsigned int len;

public:
    Array(void) : array(nullptr), len(0) {}

    Array(unsigned int n) : array(new T[n]()), len(n) {}

    Array(Array const &arr) : array(nullptr), len(0) { *this = arr; }

    ~Array()
    {
        if (this->array != nullptr)
            delete[] this->array;
    }

    T &operator[](unsigned int index)
    {
        if ((index < 0) || (index >= this->len))
            throw IndexOutOfBoundaryException();
        return (array[index]);
    }

    Array &operator=(Array const &rhs)
    {
        if (this == &rhs)
            return (*this);

        if (this->array != nullptr)
            delete[] this->array;
        this->len = rhs.len;
        this->array = new T[rhs.len];
        for (unsigned int i = 0; i < rhs.len; i++)
        {
            this->array[i] = rhs.array[i];
        }
        return (*this);
    }

    unsigned int size() const
    {
        return this->len;
    }

    void displayArray()
    {
        for (unsigned int i = 0; i < this->len; i++)
            std::cout << std::setw(7) << this->array[i] << " | ";
    };

    class IndexOutOfBoundaryException : public MyExceptions
    {
    public:
        IndexOutOfBoundaryException() : MyExceptions("Err: IndexOutOfBoundary.") {}
    };
};

#endif
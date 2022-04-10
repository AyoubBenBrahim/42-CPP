#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T * arr, size_t len, void (*func)(T  &))
{
    size_t  i;

    for (i = 0; i < len; i++)
    {
        (*func)(arr[i]);
    }
}

template <typename T>
void    incr(T &elem)
{
    elem++;
}

template <typename T>
void    print(T &elem)
{
    std::cout << elem << "\t";
}

template <typename T>
void    to_Upper(T &str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:50:37 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:50:41 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fractionalBits = 8;

/*
                                         ******** Constructors ********
*/

Fixed::Fixed()
{
    this->setRawBits(0);
}

Fixed::~Fixed()
{
}

//  int to fixed point
Fixed::Fixed(int const interger)
{
    this->setRawBits(interger);
}

//  float to fixed point
Fixed::Fixed(float const floatingPoint)
{
    this->setRawBits(floatingPoint);
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

/*
************************************************************************
*/

/*
                                         ******** Overloaders ********
*/

// rhs = right hand side of the assignment

Fixed &Fixed::operator=(const Fixed &rhs)
{
    if (this == &rhs) // CHECK FOR SELF-ASSIGNMENT
        return *this;
    this->fixedPoint = rhs.getRawBits();
    return *this;
}

// insertion and extraction operators
std::ostream &operator<<(std::ostream &outStream, Fixed const &rhs)
{
    outStream << rhs.toFloat();
    return outStream;
}

// comparison operators: >, <, >=, <=, == and !=

bool Fixed::operator>(Fixed const &rhs) const { return (this->getRawBits() > rhs.getRawBits()); }
bool Fixed::operator>=(Fixed const &rhs) const { return (this->getRawBits() >= rhs.getRawBits()); }
bool Fixed::operator<(Fixed const &rhs) const { return (this->getRawBits() < rhs.getRawBits()); }
bool Fixed::operator<=(Fixed const &rhs) const { return (this->getRawBits() <= rhs.getRawBits()); }
bool Fixed::operator==(Fixed const &rhs) const { return (this->getRawBits() == rhs.getRawBits()); }
bool Fixed::operator!=(Fixed const &rhs) const { return (this->getRawBits() != rhs.getRawBits()); }

// Compound Assignment Operators += -= *=

// Four arithmetic operators: +, -, *, and /

// u can Define your binary arithmetic operators using your compound assignment operators.
Fixed Fixed::operator+(Fixed const &rhs) { return (this->toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(Fixed const &rhs) { return (this->toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(Fixed const &rhs) { return (this->toFloat() * rhs.toFloat()); }

Fixed Fixed::operator/(Fixed const &rhs)
{
    if (rhs.toFloat() == 0)
    {
        std::cout << "Denominator should be != 0" << std::endl;
        exit(0);
    }

    return (this->toFloat() / rhs.toFloat());
}

//  pre-increment, post-increment, pre-decrement and post-decrement

// prefix
Fixed &Fixed::operator++(void)
{
    ++fixedPoint;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    --fixedPoint;
    return (*this);
}

// postfix
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixedPoint++;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixedPoint--;
    return (temp);
}

/*
************************************************************************
*/

/*
                                         ******** Getters & Setters ********
*/

int Fixed::getRawBits(void) const
{
    return (this->fixedPoint);
}

int Fixed::getFractionalBits(void)
{
    return (this->fractionalBits);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPoint = raw << getFractionalBits();
}

void Fixed::setRawBits(float const raw)
{
    this->fixedPoint = static_cast<int>(round(raw * (1 << getFractionalBits())));
}

/*
************************************************************************
*/

/*
                                         ******** Member Functions ********
*/

// fixed to floating
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->fixedPoint) / (1 << Fixed::fractionalBits);
}

//  fixed to integer
int Fixed::toInt(void) const
{
    return (this->fixedPoint >> Fixed::fractionalBits);
}

// fun that takes references on two fixed point values and returns a reference

Fixed &min(Fixed &val1, Fixed &val2)
{
    return (val1 < val2 ? val1 : val2);
}

Fixed &max(Fixed &val1, Fixed &val2)
{
    return (val1 > val2 ? val1 : val2);
}

// an overload that takes references on two constant fixed point values
// and returns a reference to constant value.

Fixed const &Fixed::min(Fixed const &val1, Fixed const &val2)
{
    return (val1 < val2 ? val1 : val2);
}

Fixed const &Fixed::max(Fixed const &val1, Fixed const &val2)
{
    return (val1 > val2 ? val1 : val2);
}

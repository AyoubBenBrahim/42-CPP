/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:11 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:49:14 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed()
{
    std::cout << "Default Constructor called" << std::endl;
    this->setRawBits(0);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// convert int to fixed(8) point value
Fixed::Fixed(int const interger)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(interger);
}

// convert float to fixed(8) point value
Fixed::Fixed(float const floatingPoint)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(floatingPoint);
}

// Copy constructor
Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &fxOverload)
{
    std::cout << "Assignation Operator Overload" << std::endl;
    if (this == &fxOverload)
        return *this;
    this->fixedPoint = fxOverload.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return (this->fixedPoint);
}

int Fixed::getFractionalBits(void)
{
    return (this->fractionalBits);
}

// overload the setRawBits function
void Fixed::setRawBits(int const raw)
{
    // raw * (2^fractionBits)
    this->fixedPoint = raw << getFractionalBits();
}

void Fixed::setRawBits(float const raw)
{
    this->fixedPoint = static_cast<int>(round(raw * (1 << getFractionalBits())));
}

// fixed to floating
float Fixed::toFloat(void) const
{
    // x << k <=======> x*2^fractionbits
    return static_cast<float>(this->fixedPoint) / (1 << Fixed::fractionalBits);
}

//  fixed integer
int Fixed::toInt(void) const
{
    // x >> k <========> fixedPoint/(2^fracBits)
    return (this->fixedPoint >> Fixed::fractionalBits); // trunced to int
}

std::ostream &operator<<(std::ostream &outStream, Fixed const &fx)
{
    outStream << fx.toFloat();
    return outStream;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:48:46 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:48:49 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed()
{
    std::cout << "Default Constructor called" << std::endl;
    this->rawBits = 0;
    // this->setRawBits(0);
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
    this->rawBits = fxOverload.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
    return;
}

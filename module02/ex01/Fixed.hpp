LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:15 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:49:18 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
public:
    Fixed(void);
    ~Fixed(void);
    Fixed(int const integer);
    Fixed(float const floatingPoint);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &fxOverload);

    int getRawBits(void) const;
    int getFractionalBits(void);
    void setRawBits(int const raw);
    void setRawBits(float const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int fixedPoint;
    static const int fractionalBits;
};

std::ostream &operator<<(std::ostream &file, Fixed const &i);

#endif

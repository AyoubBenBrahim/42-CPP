/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:48:51 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:48:55 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <iostream>
#include <string>

class Fixed
{
public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &fxOverload);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int rawBits;
    static const int fractionalBits;
};

#endif

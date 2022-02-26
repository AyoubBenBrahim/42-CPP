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

    bool operator>(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;

    // Fixed &operator+=(const Fixed &rhs);
    // Fixed &operator-=(const Fixed &rhs);
    // Fixed &operator*=(const Fixed &rhs);

    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator*(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    static const Fixed &min(Fixed const &val1, Fixed const &val2);
    static const Fixed &max(Fixed const &val1, Fixed const &val2);

private:
    int fixedPoint;
    static const int fractionalBits;
};

//Defined outside of class
std::ostream &operator<<(std::ostream &file, Fixed const &i);

#endif

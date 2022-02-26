/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:50:51 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:50:53 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "\n";

	Fixed c(10);
	Fixed d(2.25f);
	Fixed zero(0);

	std::cout << std::endl
			  << "c: " << c << " d: " << d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;

	if (c < d)
		std::cout << "c < d" << std::endl;
	else
		std::cout << "c > d" << std::endl;

	std::cout << "d / zero : " << d / zero << std::endl;

	/*
	expected output

	0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/
	return 0;
}

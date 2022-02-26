/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:00 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/26 16:49:02 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{

  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;

  std::cout << "\n ***** Expected output *****\n\n";
  std::cout << "Default constructor called\n"
               "Copy constructor called\n"
               "Assignation operator called\n"
               "getRawBits member function called\n"
               "Default constructor called\n"
               "Assignation operator called\n"
               "getRawBits member function called\n"
               "getRawBits member function called\n"
               "0\n"
               "getRawBits member function called\n"
               "0\n"
               "getRawBits member function called\n"
               "0\n"
               "Destructor called\n"
               "Destructor called\n"
               "Destructor called\n";

  return 0;
}

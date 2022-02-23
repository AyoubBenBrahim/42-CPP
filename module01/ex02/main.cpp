/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:21:22 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str; 
	std::string&	stringREF = str;

	std::cout << "\n ** Display the address in memory **\n";

	std::cout << "\nstr		= " << &str ;
	std::cout << "\nstringPTR	= " << stringPTR ;
	std::cout << "\nstringREF	= " << &stringREF ;

	std::cout << "\n\n ** Display the values in memory **\n";

	std::cout << "\nstr		= " << str ;
	std::cout << "\nstringPTR	= " << *stringPTR ;
	std::cout << "\nstringREF	= " << stringREF << "\n" ;
}

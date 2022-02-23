/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:24:05 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:24:08 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {}

Karen::~Karen(void) {}

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pic"
				 "kle-special-ketchup burger. I just love it!"
			  << "\n\n";
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’"
				 "t put enough! If you did I would not have to ask for it!"
			  << "\n\n";
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
				 "I’ve been coming here for years and you just started working here last month."
			  << "\n\n";
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
			  << "\n\n";
}

LEVEL hash(std::string const &level)
{
	if (level == "debug")
		return DEBUG;
	else if (level == "info")
		return INFO;
	else if (level == "warning")
		return WARNING;
	else if (level == "error")
		return ERROR;
	
	return SHUT_UP;
}

void Karen::complain(std::string level)
{
	Karen karen;

	switch (hash(level))
	{
	case DEBUG:
		std::cout << "[ DEBUG ]\n";
		ptrToMemberFunc(&karen, &Karen::debug);
		// break;
	case INFO:
		std::cout << "[ INFO ]\n";
		ptrToMemberFunc(&karen, &Karen::info);
		// break;
	case WARNING:
		std::cout << "[ WARNING ]\n";
		ptrToMemberFunc(&karen, &Karen::warning);
		// break;
	case ERROR:
		std::cout << "[ ERROR ]\n";
		ptrToMemberFunc(&karen, &Karen::error);
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void Karen::ptrToMemberFunc(Karen *pKaren, void (Karen::*pfn)(void))
{
	(pKaren->*pfn)();
}

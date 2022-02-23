/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:23:39 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:23:42 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {}

Karen::~Karen(void) {}

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pic"
				 "kle-special-ketchup burger. I just love it!"
			  << "\n";
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’"
				 "t put enough! If you did I would not have to ask for it!"
			  << "\n";
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve bee"
				 "n coming here for years and you just started working here last month."
			  << "\n";
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
			  << "\n";
}

LEVEL hash(std::string const &level)
{
	if (level == "debug")
		return DEBUG;
	if (level == "info")
		return INFO;
	if (level == "warning")
		return WARNING;
	return ERROR;
}

void Karen::complain(std::string level)
{
	Karen karen;

	switch (hash(level))
	{
	case DEBUG:
		// std::cout << "-----debuggggggggggg----\n";
		ptrToMemberFunc(&karen, &Karen::debug);
		break;
	case INFO:
		// std::cout << "-----infooooooooooo-----\n";
		ptrToMemberFunc(&karen, &Karen::info);
		break;
	case WARNING:
		// std::cout << "-----warnning-----\n";
		ptrToMemberFunc(&karen, &Karen::warning);
		break;
	case ERROR:
		// std::cout << "-----errorr----\n";
		ptrToMemberFunc(&karen, &Karen::error);
	}
}

void Karen::ptrToMemberFunc(Karen *pKaren, void (Karen::*pfn)(void))
{
	(pKaren->*pfn)();
}

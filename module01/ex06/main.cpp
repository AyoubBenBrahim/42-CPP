/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:24:18 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:24:19 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Karen.hpp"

std::string toLower(std::string str)
{
	std::string out = "";

    for (size_t j = 0; j < str.length(); j++)
		out += tolower(str[j]);
	return (out);
}

int main(int ac, char **av)
{
	Karen karen;

	if (ac != 2)
	{
		std::cerr << "Usage: \n	./karenFilter debug/info/warning/error"
				  << "\n";
		return (1);
	}
	std::string level = toLower(av[1]);
	karen.complain(level);

	karen.~Karen();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:23:05 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:23:07 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substitute.hpp"
// #define ENABLE_DEBUG

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: \n"
				  << "	./replace [inputFile] [stringToFind] [replacment]" << std::endl;
		return EXIT_FAILURE;
	}

	if (!find_replace(av[1], av[2], av[3]))
		return EXIT_FAILURE;

#ifdef ENABLE_DEBUG

	std::ifstream inputStream((av[1] + std::string(".replace")).c_str());
	std::string line;
	int count = 0;
	while (std::getline(inputStream, line))
	{
		if (line.find(av[3]) != std::string::npos)
		{

			std::cout << "found at line ["<< count + 1 << "]" << std::endl;
			std::cout << line << "\n\n";
		}
		count++;
	}
#endif

	return EXIT_SUCCESS;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:23:24 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:23:27 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substitute.hpp"

bool find_replace(std::string inputFile, std::string toSearch, std::string _replace)
{

    std::string line;
    std::string outputFile = "inputFile.replace";

    // outputFile = "inputFile.replace";
    if (toSearch.length() == 0 || _replace.length() == 0)
    {
        std::cout << "Empty Input is not Allowed !\n";
        return 0;
    }

    std::ifstream inputStream(inputFile);
    std::ofstream outputStream(outputFile);
    if (!inputStream.is_open() || !outputStream.is_open())
    {
        std::cerr << "Could not open the inputFile '"
                  << inputFile << "'" << std::endl;
        remove(outputFile.c_str());
        return false;
    }

    while (std::getline(inputStream, line))
    {
        /*
		*** Find starting position
		*/
        size_t pos = line.find(toSearch);
        while (pos != std::string::npos)
        {
            line.replace(pos, toSearch.size(), _replace);
            /*
			*** Get the next occurrence from the current position
			*/
            pos = line.find(toSearch, pos + _replace.size());
        }
        outputStream << line << "\n";
    }
    if (rename(outputFile.c_str(), inputFile.append(".replace").c_str()) != 0)
        std::cerr << "Error Renaming File\n";
    inputStream.close();
    outputStream.close();
    return true;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:21:04 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:07 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string randomNameGenerator(int n)
{
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						'h', 'i', 'j', 'k', 'l', 'm', 'n',
						'o', 'p', 'q', 'r', 's', 't', 'u',
						'v', 'w', 'x', 'y', 'z' };

	std::string res = "";
	for (int i = 0; i < n; i++)
		res = res + alphabet[rand() % 26];
	
	return res;
}

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombyHord = new Zombie[N];

    zombyHord[0].setname(name);
    zombyHord[0].announce();
    for (int z = 1; z < N; z++)
    {
        zombyHord[z].setname(randomNameGenerator(4));
        zombyHord[z].announce();
    }
    return zombyHord;
}

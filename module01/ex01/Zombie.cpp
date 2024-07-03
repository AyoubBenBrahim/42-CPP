LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:20:56 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:20:59 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string _name):name(_name)
{
	this->announce();
}

Zombie::~Zombie()
{
    std::cout << "<" << this->name << "> Destroyed !" << std::endl;
}

std::string	Zombie::getName()
{
	return (this->name);
}

void	Zombie::setname(std::string zName)
{
	this->name = zName;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

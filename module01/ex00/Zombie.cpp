/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:20:14 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:20:18 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name):name(_name)
{
	this->announce();
}

Zombie::~Zombie()
{
    std::cout << "<" << this->name << "> Destroyed !" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

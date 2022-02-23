/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:09 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:12 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name (_name){}

void HumanB::attack(void)
{
	std::cout << getName() << " attacks with his " << weaponPtr->getType() << std::endl;
}

std::string HumanB::getName()
{
    return name;
}

void HumanB::setWeapon(Weapon& _weaponRef)
{
	weaponPtr = &_weaponRef;
}

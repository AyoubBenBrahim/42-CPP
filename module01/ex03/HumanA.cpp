/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:21:49 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:58 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weaponRef) : weaponRef(_weaponRef)
{
    name = _name;
}

std::string HumanA::getName()
{
    return name;
}

void HumanA::attack(void)
{
    std::cout << getName() << " attacks with his " << weaponRef.getType() << std::endl;
}

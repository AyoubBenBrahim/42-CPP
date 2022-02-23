/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:24 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:26 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string weaponTp)
{
    setType(weaponTp);
}

std::string Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string weaponTp)
{
    this->type = weaponTp;
}

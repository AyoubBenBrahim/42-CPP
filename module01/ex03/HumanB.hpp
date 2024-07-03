LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:16 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:19 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon*		weaponPtr;
	std::string	name;

public:
	HumanB(std::string _name);
	std::string getName(void);
	void setWeapon(Weapon& _weaponPtr);
	void attack(void);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:00 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:08 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon& weaponRef;
	std::string name;

public:
	HumanA(std::string _name, Weapon& _weaponRef);
	std::string getName(void);
	void attack(void);
};

#endif

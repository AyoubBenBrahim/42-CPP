/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:28 by aybouras          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:30 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string weaponTp);
	std::string getType();
	void setType(std::string weaponTp);
};

#endif

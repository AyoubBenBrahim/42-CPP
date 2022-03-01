/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:25:12 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:25:14 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <unistd.h>

int main(void)
{
	ClapTrap defaultClapTrap;
	defaultClapTrap.setName("defaultClapTrap");

	ScavTrap defaultScavTrap;
	defaultScavTrap.setName("defaultScavTrap");

	ClapTrap ClapTrapAAA("ClapTrap11111");

	ScavTrap ScavTrapAAA("ScavTrap11111");

	ClapTrap copyConstrClapTrap(ClapTrapAAA);

	ScavTrap copyConstrScavTrap(ScavTrapAAA);

	std::cout << ClapTrapAAA << std::endl;
	std::cout << ScavTrapAAA << std::endl;

	ScavTrapAAA.attack("ClapTrap11111");
	ClapTrapAAA.takeDamage(ScavTrapAAA.getAttackDamage());

	std::cout << ClapTrapAAA << std::endl;
	std::cout << ScavTrapAAA << std::endl;

	defaultScavTrap.guardGate();

	return (0);
}

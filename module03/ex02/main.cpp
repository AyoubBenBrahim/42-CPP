/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:25:42 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:25:44 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <unistd.h>

int main(void)
{
	ClapTrap defaultClapTrap;
	defaultClapTrap.setName("defaultClapTrap");

	FragTrap defaultFragTrap;
	defaultFragTrap.setName("defaultFragTrap");

	ScavTrap defaultScavTrap;
	defaultScavTrap.setName("defaultScavTrap");

	ClapTrap ClapTrapAAA("ClapTrap11111");
	FragTrap FragTrapAAA("FragTrap11111");
	ScavTrap ScavTrapAAA("ScavTrap11111");

	ClapTrap copyConstrClapTrap(ClapTrapAAA);
	ScavTrap copyConstrScavTrap(ScavTrapAAA);
	FragTrap copyConstrFragTrap(FragTrapAAA);

	std::cout << ClapTrapAAA << std::endl;
	std::cout << FragTrapAAA << std::endl;

	FragTrapAAA.attack("ClapTrap11111");
	ClapTrapAAA.takeDamage(FragTrapAAA.getAttackDamage());

	std::cout << ClapTrapAAA << std::endl;
	std::cout << FragTrapAAA << std::endl;

	defaultFragTrap.highFivesGuys();

	return (0);
}

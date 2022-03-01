/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:24:36 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:24:38 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <unistd.h>

int main(void)
{
	
	ClapTrap	defaulttt;
    defaulttt.setName("defaultRobotttt");
	

	ClapTrap	RobotAAA("ClapTrap11111");
	ClapTrap	RobotBBB("ClapTrap22222");
	

	ClapTrap	copyConstr(RobotBBB);
	

	RobotBBB.attack("ClapTrap11111");
	RobotAAA.takeDamage(RobotBBB.getAttackDamage());
	

	std::cout << RobotBBB << std::endl;
	

	RobotBBB.attack("Ukraine");
	std::cout << std::endl << RobotAAA << std::endl;
	

	RobotAAA.beRepaired(10);
	std::cout << RobotAAA;
	
}

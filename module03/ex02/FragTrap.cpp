LOGIN/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:25:27 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:25:29 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(void)
{
    std::cout << "FragTrap Default Constructor called\n\n";
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap: " << this->getName() <<" Destroyed.... \n\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor called...\n";
    *this = copy;
    std::cout << "FragTrap : " + this->getName() << "  Cloned successfully.\n\n";
}

FragTrap::FragTrap(std::string const &_name) : ClapTrap(_name,  100,  100,  30)
{
    std::cout << "Constructor with Initialization List\n"
               << "  FragTrap:  " << this->getName()
              << "\nHit points: "
              << this->getHitPoints()
              << "\nEnergy points: "
              << this->getEnergyPoints()
              << "\nAttack damage: "
              << this->getAttackDamage()
              << "\n\n";
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
     if (this == &rhs)
        return *this;

    this->name = rhs.getName();
    this->hitPoints = rhs.getHitPoints();
    this->energyPoints = rhs.getEnergyPoints();
    this->attackDamage = rhs.getAttackDamage();

    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "I request a high five!! \n\n";
	return ;
}

std::ostream &operator<<(std::ostream &outStream, FragTrap const &rhs)
{
    outStream << "  FragTrap: " << rhs.getName()
              << "\n    Hit points: "
              << rhs.getHitPoints()
              << "\n    Energy points: "
              << rhs.getEnergyPoints()
              << "\n    Attack damage: "
              << rhs.getAttackDamage()
              << "\n\n";

    return outStream;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:24:20 by aybouras          #+#    #+#             */
/*   Updated: 2022/03/01 09:24:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called\n\n";
    // setName("nammmmmmmmmmmmme");
    // setHitPoints(10);
    // setEnergyPoints(10);
    // setAttackDamage(0);
}

ClapTrap::ClapTrap(std::string const &_name) : name(_name),
                                               hitPoints(10),
                                               energyPoints(10),
                                               attackDamage(0)
{
    std::cout << "Constructor with Initialization List\n"
               << "      " << this->getName()
              << "\nHit points: "
              << this->getHitPoints()
              << "\nEnergy points: "
              << this->getEnergyPoints()
              << "\nAttack damage: "
              << this->getAttackDamage()
              << "\n\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << this->getName() <<" Destroyed.... \n\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy Constructor called...\n";
    *this = copy;
    std::cout << "\nName : " + this->getName() << "  Cloned successfully.\n\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    // std::cout << "Assignation Operator Overload\n";
    if (this == &rhs)
        return *this;
    this->name = rhs.getName();
    this->hitPoints = rhs.getHitPoints();
    this->energyPoints = rhs.getEnergyPoints();
    this->attackDamage = rhs.getAttackDamage();
    return *this;
}

std::string ClapTrap::getName(void) const { return (this->name); }
unsigned int ClapTrap::getHitPoints(void) const { return (this->hitPoints); }
unsigned int ClapTrap::getEnergyPoints(void) const { return (this->energyPoints); }
unsigned int ClapTrap::getAttackDamage(void) const { return (this->attackDamage); }

void ClapTrap::setName(std::string _name) { this->name = _name; }
void ClapTrap::setHitPoints(int amount) { this->hitPoints = amount; }
void ClapTrap::setEnergyPoints(unsigned int amount) { this->energyPoints = amount; }
void ClapTrap::setAttackDamage(unsigned int amount) { this->attackDamage = amount; }

void ClapTrap::attack(std::string const &target)
{
    if(this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
    {
        std::cout<< "<" << this->getName() << "> I have no Energy/Points Repairrrrrrrrre meee\n\n";
        return ;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 10);
    std::cout << "<" << this->getName() << "> attacks <" << target << "> , causing <" << this->getAttackDamage() << "> points of damage!\n\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int pointsToLoose;

    if (amount > this->getHitPoints())
    {
        pointsToLoose = amount - this->getHitPoints();
        this->setHitPoints(0);
    }
    else
    {
        pointsToLoose = this->getHitPoints();
        this->setHitPoints(this->hitPoints - amount);
    }
    std::cout << this->getName() << " Lost <" << pointsToLoose << "> Points\n\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->setEnergyPoints(this->energyPoints + amount);
    this->setHitPoints(this->hitPoints + amount);
    std::cout << this->getName() << " Earned <" << amount << "> Points\n\n";
}

std::ostream &operator<<(std::ostream &outStream, ClapTrap const &rhs)
{
    outStream << "      " << rhs.getName()
              << "\nHit points: "
              << rhs.getHitPoints()
              << "\nEnergy points: "
              << rhs.getEnergyPoints()
              << "\nAttack damage: "
              << rhs.getAttackDamage()
              << "\n\n";

    return outStream;
}

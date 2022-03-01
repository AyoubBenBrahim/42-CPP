#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap Default Constructor called\n\n";
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap: " << this->getName() <<" Destroyed.... \n\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "ScavTrap : " + this->getName() << "  Cloned successfully.\n\n";
}

ScavTrap::ScavTrap(std::string const &_name, int _hitPoints, int _energyPoints, int _attackDamage)
{
    this->setName(_name);
    this->setHitPoints(_hitPoints);
    this->setEnergyPoints(_energyPoints);
    this->setAttackDamage(_attackDamage);

    std::cout << "Constructor with Initialization List\n"
              << "  ScavTrap :    " << this->getName()
              << "\nHit points: "
              << this->getHitPoints()
              << "\nEnergy points: "
              << this->getEnergyPoints()
              << "\nAttack damage: "
              << this->getAttackDamage()
              << "\n\n";
}

ScavTrap::ScavTrap(std::string const &_name) : ClapTrap(_name,  100,  50,  20)
{
    std::cout << "Constructor with Initialization List\n"
               << "  ScavTrap:  " << this->getName()
              << "\nHit points: "
              << this->getHitPoints()
              << "\nEnergy points: "
              << this->getEnergyPoints()
              << "\nAttack damage: "
              << this->getAttackDamage()
              << "\n\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
     if (this == &rhs)
        return *this;

    this->name = rhs.getName();
    this->hitPoints = rhs.getHitPoints();
    this->energyPoints = rhs.getEnergyPoints();
    this->attackDamage = rhs.getAttackDamage();

    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    ClapTrap::attack(target);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap <" << this->getName() << "> have enterred Gate keeper mode.\n\n";
}

std::ostream &operator<<(std::ostream &outStream, ScavTrap const &rhs)
{
    outStream << "  ScavTrap: " << rhs.getName()
              << "\n    Hit points: "
              << rhs.getHitPoints()
              << "\n    Energy points: "
              << rhs.getEnergyPoints()
              << "\n    Attack damage: "
              << rhs.getAttackDamage()
              << "\n\n";

    return outStream;
}
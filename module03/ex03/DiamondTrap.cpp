
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap Default Constructor called\n\n";
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap: " << this->name << " Destroyed.... \n\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap : " + this->name << "  Cloned successfully.\n\n";
}

DiamondTrap::DiamondTrap(std::string const &_name)
    : ScavTrap(_name, 100, 50, 20), FragTrap(_name, 100, 100, 30)
{
    this->name = _name;
    ClapTrap::setName(_name + ("_clap_name"));
    //  = this->name.append("_clap_name");
    this->hitPoints = FragTrap(name).getHitPoints();       // 100
    this->energyPoints = ScavTrap(name).getEnergyPoints(); // 50
    this->attackDamage = FragTrap(name).getAttackDamage(); // 30

    std::cout << "Constructor with Initialization List\n"
              << "  DiamondTrap:  " << this->name
              << "\nHit points: "
              << this->getHitPoints()
              << "\nEnergy points: "
              << this->getEnergyPoints()
              << "\nAttack damage: "
              << this->getAttackDamage()
              << "\n\n";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
    if (this == &rhs)
        return *this;

    this->name = rhs.getName();
    this->hitPoints = rhs.getHitPoints();
    this->energyPoints = rhs.getEnergyPoints();
    this->attackDamage = rhs.getAttackDamage();

    return *this;
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "my name <" << this->name << "> ClapTrap::name <" << ClapTrap::name << "> \n";
}

std::ostream &operator<<(std::ostream &outStream, DiamondTrap const &rhs)
{
    outStream << "  DiamondTrap: " << rhs.getName()
              << "\n    Hit points: "
              << rhs.getHitPoints()
              << "\n    Energy points: "
              << rhs.getEnergyPoints()
              << "\n    Attack damage: "
              << rhs.getAttackDamage()
              << "\n\n";

    return outStream;
}
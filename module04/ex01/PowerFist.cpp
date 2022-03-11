

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power First", 8, 50)
{
}

PowerFist::~PowerFist() 
{
}

PowerFist &PowerFist::operator=(const PowerFist &rhs) 
{
	std::cout  << "<PowerFist> assignation operator is called." << std::endl;

	if (this == &rhs)
        return *this;
    this->weaponName = rhs.getName();
    this->weaponDamage = rhs.getDamage();
    this->weaponpApCost = rhs.getAPCost();
	return *this;
}

PowerFist::PowerFist(const PowerFist &copy) : AWeapon(copy)
{
	// std::cout  << "<PowerFist> copy constructor is called." << std::endl;
	*this = copy;
}

void PowerFist::attack() const 
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

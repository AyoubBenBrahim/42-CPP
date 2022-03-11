


#include "AWeapon.hpp" 

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
    : weaponName(name), weaponpApCost(apcost), weaponDamage(damage)
{
}

AWeapon::AWeapon(AWeapon const &copy)
{
    *this = copy;
}

AWeapon::~AWeapon(void)
{
    	std::cout << "<AWeapon> [" << this->getName() << "] is destroyed."  << std::endl;

}

std::string AWeapon::getName() const
{
    return (this->weaponName);
}

int AWeapon::getAPCost() const
{
    return (this->weaponpApCost);
}

int AWeapon::getDamage() const
{
    return (this->weaponDamage);
}

AWeapon &AWeapon::operator=(AWeapon const &rhs)
{
    if (this == &rhs)
        return *this;

    this->weaponName = rhs.getName();
    this->weaponpApCost = rhs.getAPCost();
    this->weaponDamage = rhs.getDamage();

    return *this;
}
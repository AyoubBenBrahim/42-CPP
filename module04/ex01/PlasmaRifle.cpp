

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &rhs)
{
    // std::cout  << "<PlasmaRifle> assignation operator is called."  << std::endl;
    if (this == &rhs)
        return *this;
    this->weaponName = rhs.getName();
    this->weaponDamage = rhs.getDamage();
    this->weaponpApCost = rhs.getAPCost();

    return *this;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy) : AWeapon(copy)
{
    // std::cout  << "<PlasmaRifle> copy constructor is called."  << std::endl;
    *this = copy;
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
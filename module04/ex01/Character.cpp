#include "Character.hpp"

Character::Character()
    : name("character"), nbrAP(40), weaponPTR(nullptr)
{
}

Character::Character(std::string const & _name)
    : name(_name), nbrAP(40), weaponPTR(nullptr)
{
}

Character::~Character()
{
    std::cout << "<Character> [" << this->getName() << "] is destroyed." << std::endl;
}

Character::Character(Character const &copy)
{
    // std::cout   << "<Character> Copy constructor is called."  << std::endl;
    *this = copy;
}

Character &Character::operator=(Character const &rhs)
{
    // std::cout  << "<Character> Assignation operator is called."  << std::endl;

    if (this == &rhs)
        return *this;
    this->nbrAP = rhs.getAPnbr();
    this->name = rhs.getName();

    return *this;
}

std::string Character::getName(void) const { return (this->name); }
int Character::getAPnbr(void) const { return (this->nbrAP); }
AWeapon *Character::getWeaponPTR(void) const { return (this->weaponPTR); }

void Character::recoverAP()
{
    this->nbrAP += 10;
    if (this->getAPnbr() > 40)
        this->nbrAP = 40;
}

void Character::equip(AWeapon *aWeapon)
{
    this->weaponPTR = aWeapon;
}

void Character::attack(Enemy *&enemy)
{

    if (!this->getWeaponPTR() || this->getAPnbr() < this->getWeaponPTR()->getAPCost())
    {
        std::cout << "Impossible !!!\n";
        return;
    }
    else
    {
        std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->getWeaponPTR()->getName() << std::endl;
        this->getWeaponPTR()->attack();
        enemy->takeDamage(this->getWeaponPTR()->getDamage());
        this->nbrAP -= this->getWeaponPTR()->getAPCost();
        if (enemy->getHP() <= 0)
        {
            delete enemy;
            enemy = nullptr;
        }
    }
}

std::ostream &operator<<(std::ostream &outStream, const Character &rhs)
{
    if (rhs.getWeaponPTR())
        return outStream << rhs.getName() << " has " << rhs.getAPnbr() << " AP and wields a " << rhs.getWeaponPTR()->getName() << std::endl;
    else
        return outStream << rhs.getName() << " has " << rhs.getAPnbr() << " AP and is unarmed" << std::endl;
}

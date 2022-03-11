
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
    std::cout << "“Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &copy) : Enemy(copy)
{
    // std::cout << "“Gaaah. Me want smash heads !" << std::endl;
    *this = copy;
}

SuperMutant::~SuperMutant(void)
{
    std::cout << "Aaargh..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs)
{
    this->enemyHP = rhs.enemyHP;
    this->enemyType = rhs.enemyType;
    return (*this);
}

void SuperMutant::takeDamage(int damage)
{
    damage -= 3;
    if (damage > 0)
    {
        if (this->getHP() - damage >= 0)
            this->enemyHP -= damage;
        else
            this->enemyHP = 0;
    }
}

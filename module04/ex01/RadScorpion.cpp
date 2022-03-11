
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
    return;
}

RadScorpion::RadScorpion(RadScorpion const &copy) : Enemy(copy)
{
    // std::cout << "* click click click *" << std::endl;
    *this = copy;
    return;
}

RadScorpion::~RadScorpion(void)
{
    std::cout << "* SPROTCH *" << std::endl;
    return;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &rhs)
{
    if (this == &rhs)
        return *this;

    this->enemyHP = rhs.enemyHP;
    this->enemyType = rhs.enemyType;

    return (*this);
}

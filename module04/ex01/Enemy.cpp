

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
    : enemyHP(hp), enemyType(type)
{
}

Enemy::Enemy(Enemy const &copy)
{
    *this = copy;
}

Enemy::~Enemy(void)
{
}

std::string Enemy::getType() const
{
    return (this->enemyType);
}

int Enemy::getHP() const
{
    return (this->enemyHP);
}

void Enemy::takeDamage(int damage)
{
    if (damage > 0)
    {
        if (this->getHP() - damage >= 0)
            this->enemyHP -= damage;
        else
           this->enemyHP = 0;
    }
}

Enemy &Enemy::operator=(Enemy const &rhs)
{
    if (this == &rhs)
        return *this;

    this->enemyType = rhs.getType();
    this->enemyHP = rhs.getHP();

    return *this;
}

// std::ostream &operator<<(std::ostream &outStream, Enemy const &rhs)
// {
//     outStream << "I'm ";

//     return outStream;
// }


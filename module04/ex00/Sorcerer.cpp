
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &_name, std::string const &_title)
    : sorcererName(_name), sorcererTitle(_title)
{
    std::cout << this->getSorcererName() << ", " << this->getSorcererTitle() << ", is born !\n";
}

Sorcerer::Sorcerer(Sorcerer const &copy)
{
    *this = copy;
    std::cout << copy.getSorcererName() << ", " << copy.getSorcererTitle() << ", is born !\n";
}

Sorcerer::~Sorcerer(void)
{
    std::cout << this->getSorcererName() << ", " << this->getSorcererTitle() << ", is dead. Consequences will never be the same !\n";
}

std::string Sorcerer::getSorcererName() const
{
    return (this->sorcererName);
}

std::string Sorcerer::getSorcererTitle() const
{
    return (this->sorcererTitle);
}

void Sorcerer::polymorph(Victim const &victim) const
{
    victim.getPolymorphed();
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs)
{
    if (this == &rhs)
        return *this;

    this->sorcererName = rhs.getSorcererName();
    this->sorcererTitle = rhs.getSorcererTitle();

    return *this;
}

std::ostream &operator<<(std::ostream &outStream, Sorcerer const &rhs)
{
    outStream << "I'm " << rhs.getSorcererName() << ", " << rhs.getSorcererTitle() << ", and I like ponies !\n";

    return outStream;
}
#include "Victim.hpp"

Victim::Victim(std::string const &_name) : victimName(_name)
{
    std::cout << "Some random victim called " <<  this->getVictimName() << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &copy)
{
    *this = copy;
    std::cout << "Some random victim called " << copy.getVictimName() << " just appeared!" << std::endl;
}

Victim::~Victim(void)
{
    std::cout << "Victim " << this->getVictimName() << " just died for no apparent reason !" << std::endl;
}

Victim &Victim::operator=(Victim const &rhs)
{
    if (this == &rhs)
        return *this;

    this->setVictimName(rhs.getVictimName());
    return *this;
}

std::string Victim::getVictimName() const
{
    return (this->victimName);
}

void Victim::setVictimName(std::string const & _name)
{
   this->victimName = _name;
}

void Victim::getPolymorphed(void) const
{
    std::cout << GREEN << this->getVictimName() << " has been turned into a cute little sheep !\n" << RESET;
}

std::ostream &operator<<(std::ostream &outStream, Victim const &rhs)
{
    outStream << "I'm " << rhs.getVictimName() << " and I like otters !\n";
    return outStream;
}
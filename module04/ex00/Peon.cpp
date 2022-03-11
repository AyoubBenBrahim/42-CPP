
#include "Peon.hpp"

Peon::Peon(std::string const &_name) : Victim(_name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void) 
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

Peon::Peon(Peon const &copy) : Victim(copy)
{
    *this = copy;
	std::cout << "Some random Peon called " << copy.getVictimName() << " just appeared !\n";
}

Peon &Peon::operator=(Peon const &rhs)
{
    if (this == &rhs)
        return *this;

   	this->getVictimName() = rhs.getVictimName();

    return *this;
}

void		Peon::getPolymorphed(void) const
{
	std::cout << GREEN << this->getVictimName() << " has been turned into a pink pony !\n" << RESET;
	return;
}
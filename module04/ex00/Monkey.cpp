
#include "Monkey.hpp"

Monkey::Monkey(std::string const &_name) : Victim(_name)
{
	std::cout << "Wak Wak." << std::endl;
}

Monkey::~Monkey(void) 
{
	std::cout << "Monkey died..." << std::endl;
	return;
}

Monkey::Monkey(Monkey const &copy) : Victim(copy)
{
    *this = copy;
	std::cout << "Some random Monkey called " << copy.getVictimName() << " just appeared !\n";
}

Monkey &Monkey::operator=(Monkey const &rhs)
{
    if (this == &rhs)
        return *this;

   	this->getVictimName() = rhs.getVictimName();

    return *this;
}

void		Monkey::getPolymorphed(void) const
{
	std::cout << GREEN << this->getVictimName() << " has been turned into a white Monkey !\n" << RESET;
	return;
}
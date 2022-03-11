
#include "Macaque.hpp"

Macaque::Macaque(std::string const &_name) : Monkey(_name)
{
	std::cout << "Mac Mac." << std::endl;
}

Macaque::~Macaque(void) 
{
	std::cout << "Mac Destroyed..." << std::endl;
	return;
}

Macaque::Macaque(Macaque const &copy) : Monkey(copy)
{
    *this = copy;
	std::cout << "Some random Macaque called " << copy.getVictimName() << " just appeared !\n";
}

Macaque &Macaque::operator=(Macaque const &rhs)
{
    if (this == &rhs)
        return *this;

   	this->getVictimName() = rhs.getVictimName();

    return *this;
}

void		Macaque::getPolymorphed(void) const
{
	std::cout << GREEN << this->getVictimName() << " has been turned into a pink Macaque !\n" << RESET;
	return;
}
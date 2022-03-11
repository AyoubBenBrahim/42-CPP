#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const &copy) : AMateria("ice") // AMateria(copy)
{
	*this = copy;
	// std::cout << "Ice copy constructor\n";
}

Ice::~Ice(void)
{
}

Ice &Ice::operator=(Ice const &rhs)
{
	// std::cout << "Ice assignation operator\n";

	if (this == &rhs)
		return *this;

	this->_xp = rhs._xp;
	this->_type = rhs._type;
	// this->AMateria::operator=(src);
	return (*this);
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone() const
{
	AMateria *materia;

	if (!(materia = new Ice(*this)))
	{
		std::cerr << "Failed to Allocat.\n";
		// exit(0);
	}

	return (materia);
}

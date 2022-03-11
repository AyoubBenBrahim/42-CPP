
#include <iostream>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	// std::cout << "Cure copy constructor\n";
	*this = copy;
}

Cure::~Cure(void)
{
}

Cure &Cure::operator=(Cure const &rhs)
{
	// std::cout << "Cure assignation operator\n";

	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	this->_xp = rhs._xp;

	// this->AMateria::operator=(rhs);
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria *materia;

	if (!(materia = new Cure(*this)))
	{
		std::cerr << "Failed to Allocat.\n";
		// exit(0);
	}
	return (materia);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	this->AMateria::use(target);
}
#include "AMateria.hpp"

AMateria::AMateria()
: _xp(0)
{
}

AMateria::AMateria(std::string const &type)
: _xp(0), _type(type)
{
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
    std::cout << "AMateria copy constructor" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
    std::cout << "AMateria assignation operator" << std::endl;
    if (this == &rhs)
        return *this;

    this->_xp = rhs._xp;
    this->_type = rhs._type;

    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
     
        return (this->_type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	this->_xp += 10;
}
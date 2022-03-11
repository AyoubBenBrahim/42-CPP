#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#include "ICharacter.hpp"

class ICharacter;

class Ice : public AMateria
{
public:
    Ice(void);
    virtual ~Ice(void);
    Ice(Ice const &copy);
    Ice &operator=(Ice const &rhs);
    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif
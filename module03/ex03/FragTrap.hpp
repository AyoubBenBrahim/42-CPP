#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/**
 * virtual can be written before or after the public.
 *  Now only one copy of data/function member will be copied to class C and class B and class A becomes the virtual base class.
 * Virtual base classes offer a way to save space and avoid ambiguities in class hierarchies that use multiple inheritances.
 * When a base class is specified as a virtual base, it can act as an indirect base more than once without duplication of its data members.
 * A single copy of its data members is shared by all the base classes that use virtual base.
**/

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
        FragTrap(std::string const & _name);
		FragTrap(std::string const &_name, int _hitPoints, int _energyPoints, int _attackDamage);
		FragTrap(FragTrap const& copy);
        void highFivesGuys(void);

		FragTrap	&operator=(FragTrap const &rhs);	
};

std::ostream &operator<<(std::ostream &outStream, FragTrap const &rhs);
#endif
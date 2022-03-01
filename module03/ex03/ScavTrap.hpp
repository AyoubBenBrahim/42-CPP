#ifndef SERENA_HPP
#define SERENA_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap(void);
		~ScavTrap(void);
        ScavTrap(std::string const & _name);
		ScavTrap(std::string const &_name, int _hitPoints, int _energyPoints, int _attackDamage);
		ScavTrap(ScavTrap const& copy);

		ScavTrap	&operator=(ScavTrap const &rhs);

void attack(std::string const &target);
		void	guardGate(void);
};

std::ostream &operator<<(std::ostream &outStream, ScavTrap const &rhs);

#endif
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;

public:
    DiamondTrap(void);
    ~DiamondTrap(void);
    DiamondTrap(std::string const & _name);
    DiamondTrap(DiamondTrap const &copy);

    void	attack(std::string const & target);
    DiamondTrap &operator=(DiamondTrap const &rhs);

    void whoAmI(void);
};

std::ostream &operator<<(std::ostream &outStream, DiamondTrap const &rhs);

#endif

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

#include <unistd.h>

int main(void)
{
	std::cout << "*************  creation **************************************** \n";
	ClapTrap ClapTrapAAA("ClapTrap11111");
	ScavTrap ScavTrapAAA("ScavTrap11111");
	FragTrap FragTrapAAA("FragTrap11111");
	std::cout << "\n\n";

	std::cout << "************* defaultDiamondTrap creation **************************************** \n";
	DiamondTrap defaultDiamondTrap;
	defaultDiamondTrap.setName("defaultDiamondTrap");
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap initialized **************************************** \n";
	DiamondTrap DiamondTrapAAA("DiamondTrapAAA");
	// std::cout << DiamondTrapAAA << std::endl;
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap copied **************************************** \n";
	DiamondTrap copyConstrDiamondTrap(DiamondTrapAAA);
	std::cout << copyConstrDiamondTrap << std::endl;
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap Attack **************************************** \n";
	defaultDiamondTrap.attack("Diamond");
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap takeDamage **************************************** \n";

	DiamondTrapAAA.takeDamage(defaultDiamondTrap.getAttackDamage());
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap highFivesGuys() **************************************** \n";
	DiamondTrapAAA.highFivesGuys();
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap guardGate() **************************************** \n";
	DiamondTrapAAA.guardGate();
	std::cout << "\n\n";

	std::cout << "************* DiamondTrap whoAmI() **************************************** \n";
	DiamondTrapAAA.whoAmI();
	std::cout << "\n\n";

	std::cout << "************* Program Destruction **************************************** \n";
	return (0);
}

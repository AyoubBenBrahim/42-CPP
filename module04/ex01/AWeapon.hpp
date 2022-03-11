

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class AWeapon
{
protected:
	std::string weaponName;
	int			weaponpApCost;
	int			weaponDamage;

public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
    
	virtual ~AWeapon();
	AWeapon & operator=(AWeapon const & rhs);
	AWeapon(AWeapon const & copy);

	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};
#endif
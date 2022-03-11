
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <iostream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character 
{
private:
	std::string		name;
	int				nbrAP;
	AWeapon*		weaponPTR;

public:

	Character(void);
	Character(std::string const & _name);
	Character(Character const & src);
	~Character(void);
	Character &		operator=(Character const & rhs);

	void			recoverAP();
	void			equip(AWeapon*);
	void			attack(Enemy* &);

	std::string		getName() const;
	int				getAPnbr() const;
	AWeapon*		getWeaponPTR() const;

};

std::ostream &operator<<(std::ostream &outStream, Character const &rhs);

#endif

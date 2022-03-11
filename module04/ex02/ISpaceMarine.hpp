
#ifndef ISPACE_HPP
#define ISPACE_HPP
#include <iostream>

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine() {}
	// virtual ISpaceMarine* clone() const = 0;
	virtual void battleCry() const = 0;
	virtual void rangedAttack() const = 0;
	virtual void meleeAttack() const = 0;

		/* *******
	*** delete thios
	*/
	// TacticalMarine::TacticalMarine(std::string n);
	// for testing delete this
	public:
	std::string name;
};

#endif
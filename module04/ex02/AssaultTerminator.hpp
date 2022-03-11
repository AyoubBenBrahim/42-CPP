
#ifndef ASSAULT_HPP
#define ASSAULT_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine 
{

public:
	AssaultTerminator();
	~AssaultTerminator();
	AssaultTerminator & operator=(const AssaultTerminator & rhs);
	AssaultTerminator(const AssaultTerminator & src);

	// AssaultTerminator* clone() const; //this one ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
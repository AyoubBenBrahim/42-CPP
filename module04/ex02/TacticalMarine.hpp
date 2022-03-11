
#ifndef TACTICAL_HPP
#define TACTICAL_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{

public:
	TacticalMarine();
	~TacticalMarine();
	TacticalMarine &operator=(TacticalMarine const &rhs);
	TacticalMarine(TacticalMarine const &copy);

	// TacticalMarine *clone() const; // ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

};

#endif
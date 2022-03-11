
#ifndef PLASMA_HPP
#define PLASMA_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon 
{

public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	PlasmaRifle & operator=(PlasmaRifle const & rhs);
	PlasmaRifle(PlasmaRifle const & copy);

	virtual void attack() const;
};

#endif
#ifndef FIST_HPP
#define FIST_HPP

#include "AWeapon.hpp"
class PowerFist : public AWeapon
{

public:
	PowerFist();
	virtual ~PowerFist();
	PowerFist & operator=(PowerFist const & rhs);
	PowerFist(PowerFist const & copy);

	virtual void attack() const;
};

#endif
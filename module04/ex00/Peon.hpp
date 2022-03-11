
#ifndef PEON_HPP
#define PEON_HPP
#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{

public:
	Peon(void);
	Peon(std::string const &_name);
	Peon(Peon const &copy);
	virtual ~Peon(void);

	Peon &operator=(Peon const &rhs);
	Peon *getObject();

	virtual void getPolymorphed(void) const;
};

#endif


#ifndef MAC_HPP
# define MAC_HPP
#include <iostream>
#include "Victim.hpp"
#include "Monkey.hpp"

class	Macaque  : public Monkey 
{

public:
	Macaque (void);
    Macaque (std::string const &_name);
	Macaque (Macaque  const &copy);
	virtual ~Macaque (void);

	Macaque  &operator=(Macaque  const & rhs);

	virtual void	getPolymorphed(void) const;
};

#endif


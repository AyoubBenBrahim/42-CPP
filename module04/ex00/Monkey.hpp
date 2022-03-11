
#ifndef MONKEY_HPP
# define MONKEY_HPP
#include <iostream>
#include "Victim.hpp"

class	Monkey : public Victim 
{
public:
	Monkey(void);
    Monkey(std::string const &_name);
	Monkey(Monkey const &copy);
	virtual ~Monkey(void);

	Monkey &			operator=(Monkey const & rhs);

	virtual void	getPolymorphed(void) const;
};

#endif


#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

# define RESET			"\033[0m"
# define GREEN			"\033[32m"

class Victim
{
protected:
	std::string victimName;

public:
	Victim(void);
	Victim(std::string const &_name);
	Victim(Victim const &copy);
	Victim &operator=(const Victim &rhs);
	virtual ~Victim(void);

	std::string getVictimName(void) const;
	void setVictimName(std::string const &_name);
	virtual void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &outStream, Victim const &rhs);

#endif
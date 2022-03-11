#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Sorcerer
{

private:
	std::string sorcererName;
	std::string sorcererTitle;

public:
	Sorcerer();
	Sorcerer(std::string const &_name, std::string const &_title);
	~Sorcerer(void);
	Sorcerer(Sorcerer const &copy);
	Sorcerer &operator=(Sorcerer const &rhs);

	std::string getSorcererName() const;
	std::string getSorcererTitle() const;

	void polymorph(Victim const &) const;
};

std::ostream &operator<<(std::ostream &outStream, Sorcerer const &rhs);

#endif

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>

#include "ISquad.hpp"

// typedef struct		s_unit
// {
// 	int				id;
// 	ISpaceMarine	*unitPTR;
// 	struct s_unit	*next;
// }					t_unit;

class Unit
{
public:
   	int				id;
	ISpaceMarine	*unitPTR;
	Unit	*next;
};


class	Squad: public ISquad 
{

private:
	Unit*		head;
	Unit*		tail;

public:
	Squad(void);
	Squad(Squad const & copy);
	~Squad(void);

	Squad&          operator=(Squad const & rhs);

	int				getCount() const;
	ISpaceMarine*	getUnit(int) const;
	int				push(ISpaceMarine*);

	bool isDuplicate(ISpaceMarine *spaceMarine, Unit *head);
	// void destroyObjs(Unit **head_ref);
	void destroyObjs(Unit *head_ref);
	// std::string getName();
	Unit *getHead();
	void printList(Unit *tempHead);
};

#endif
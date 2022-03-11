#include "Squad.hpp"

void Squad::printList(Unit *tempHead)
{

	std::cout << "--show--\n";

	while (tempHead)
	{
		std::cout << tempHead->id << " " << tempHead->unitPTR->name << "\n";
		tempHead = tempHead->next;
	}
	std::cout << "----\n";
}

Squad::Squad() : head(nullptr), tail(nullptr)
{
}

Squad::~Squad()
{
	// this->destroyObjs(&this->head);
	this->destroyObjs(this->head);
}

Squad::Squad(const Squad &copy) : head(nullptr), tail(nullptr)
{
	*this = copy;
}

bool Squad::isDuplicate(ISpaceMarine *spaceMarine, Unit *head)
{

	while (head)
	{
		if (head->unitPTR == spaceMarine)
			return true;
		head = head->next;
	}
	return false;
}

// void Squad::destroyObjs(Unit **head_ref)
void Squad::destroyObjs(Unit *head_ref)
{

	Unit *current = head_ref;
	Unit *nxt = nullptr;

	while (current)
	{
		nxt = current->next;
		delete (current->unitPTR); // seg here
		delete (current);

		current = nxt;
	}
	head_ref = nullptr;
}

Squad &Squad::operator=(const Squad &rhs)
{
	if (this == &rhs)
		return *this;
	// printList(this->head);
	this->destroyObjs(this->head);
	this->head = nullptr;
	this->tail = nullptr;

	Unit *tempHead;

	if ((tempHead = rhs.head))
	{
		this->push(tempHead->unitPTR); // Upon copy construction or assignation of a Squad, the copy must be deep
		while (tempHead->next)
		{
			tempHead = tempHead->next;
			this->push(tempHead->unitPTR);
		}
	}

	return *this;
}

Unit *Squad::getHead()
{
	return (this->head);
}

ISpaceMarine *Squad::getUnit(int N) const
{
	Unit *tempHead;

	if (N < 0 || N >= this->getCount())
		return nullptr;
	tempHead = this->head;
	while (tempHead)
	{
		// std::cout << "N = " << N << " ID = " << tempHead->id << " " << tempHead->unitPTR->name << "\n";
		if (N == tempHead->id)
			break;
		tempHead = tempHead->next;
	}
	return tempHead->unitPTR;
}

int Squad::push(ISpaceMarine *spaceMarine)
{
	// std::cout << "-----pushing-------\n";
	if (spaceMarine && !isDuplicate(spaceMarine, this->head))
	{
		Unit *newUnit;

		if (!(newUnit = new Unit))
		{
			std::cout << "Failed to Allocat.\n";
			if (this->head)
				this->destroyObjs(this->head);
		}

		newUnit->unitPTR = spaceMarine;
		newUnit->next = NULL;
		if (!this->head)
		{
			// std::cout << "first insert\n";
			newUnit->id = 0;
			this->head = newUnit;
			this->tail = newUnit;
		}
		else
		{
			// std::cout << "append\n";
			newUnit->id = this->tail->id + 1;
			this->tail->next = newUnit;
			this->tail = newUnit;
		}
	}

	// std::cout << "--COUNT = --|" << Squad::getCount() << "| \n";
	// printList(this->head);

	return this->getCount();
}

int Squad::getCount() const
{
	if (this->tail) // tail->ptr
		return (this->tail->id + 1);
	return -1; //**********
}
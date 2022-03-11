
#include "Character.hpp"

Character::Character()
    : _name("Character"), head(nullptr), tail(nullptr)
{
}

Character::Character(std::string const &name)
    : _name(name), head(nullptr), tail(nullptr)
{
}

Character::Character(Character const &copy)
    : head(nullptr), tail(nullptr)
{
    	std::cout << "Character copy constructor\n";
    *this = copy;
}

Character::~Character(void)
{
    if (this->head)
        this->destroyObjs(this->head);
}

void Character::destroyObjs(MateriaInventory *head_ref)
{

    MateriaInventory *current = head_ref;
    MateriaInventory *nxt = nullptr;

    while (current)
    {
        nxt = current->next;
        delete (current->Materia);
        delete (current);

        current = nxt;
    }
    head_ref = nullptr;
}

Character &Character::operator=(Character const &rhs)
{
    std::cout << "Character assignation operator\n";

    if (this == &rhs)
        return *this;

    this->_name = rhs._name;
    if (this->head)
        this->destroyObjs(this->head);
    this->head = nullptr;
    this->tail = nullptr;

    MateriaInventory *tempHead;

    if ((tempHead = rhs.head))
    {

        this->push(tempHead->Materia->clone()); // Copy or assignation of a Character must be deep
        while (tempHead->next)
        {
            tempHead = tempHead->next;
            this->push(tempHead->Materia->clone());
        }
    }
    return (*this);
}

void Character::push(AMateria *Materia)
{
    // std::cout << "-----pushing-------\n";
    if (Materia)
    {
        MateriaInventory *newMateria;

        if (!(newMateria = new MateriaInventory))
        {
            std::cerr << "Failed to Allocat.\n";
            if (this->head)
                this->destroyObjs(this->head);
            exit(0);
        }

        newMateria->Materia = Materia;
        newMateria->next = nullptr;
        if (!this->head)
        {
            // std::cout << "first insert\n";
            newMateria->id = 0;
            this->head = newMateria;
            this->tail = newMateria;
        }
        else if (this->tail->id <= 2)
        {
            // std::cout << "append\n";
            newMateria->id = this->tail->id + 1;
            this->tail->next = newMateria;
            this->tail = newMateria;
        }
        else
        {
            std::cout << "inventory is full!" << std::endl;
            delete newMateria;
        }
    }

    // std::cout << "--COUNT = --|" << Squad::getCount() << "| \n";
    // printList(this->head);
}

std::string const &Character::getName(void) const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    this->push(m);
}

/*
void Character::garbageCollector(MateriaInventory *toRemove)
{
    if (!this->trash)
    {

        this->trash = toRemove;
        this->trashTail = toRemove;
    }
    else
    {

        trashTail->next = toRemove;
        trashTail = toRemove;
    }
}
*/

void Character::shiftList(int idx)
{
    MateriaInventory *newLst = nullptr;
    MateriaInventory *lstTail;
    MateriaInventory *temp;

    temp = this->head;
    while (temp)
    {
        if (idx != temp->id)
        {
            if (!this->head)
            {
                temp->id = 0;
                newLst = temp;
                lstTail = temp;
            }
            else
            {
                temp->id = lstTail->id + 1;
                lstTail->next = temp;
                lstTail = temp;
            }
        }
        // else
        //     garbageCollector(temp);
        temp = temp->next;
    }
    this->head = newLst;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid Boundary\n";
        return;
    }
    this->shiftList(idx);
}

void Character::use(int idx, ICharacter &target)
{
    MateriaInventory *temp;

    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid Boundary\n";
        return;
    }

    temp = this->head;
    while (temp)
    {
        if (idx == temp->id)
        {
            if (temp->Materia->getType().compare("ice") == 0 ||
                 temp->Materia->getType().compare("cure") == 0)
                temp->Materia->use(target);
            else
                std::cout << "Invalid Materia Type (expected : ice | cure)\n";
            break;
        }
        temp = temp->next;
    }
}
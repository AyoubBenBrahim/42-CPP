#include "MateriaSource.hpp"

void printList(Materia_Inventory *tempHead)
{

	std::cout << "--show--\n";

	while (tempHead)
	{
		std::cout << tempHead->id << " " << tempHead->Materia->getType() << "\n";
		tempHead = tempHead->next;
	}
	std::cout << "----\n";
}

MateriaSource::MateriaSource()
    : head(nullptr), tail(nullptr)
{
}

MateriaSource::MateriaSource(MateriaSource const &copy)
    : head(nullptr), tail(nullptr)
{
    std::cout << "MateriaSource copy constructor called.\n";
    *this = copy;
}

MateriaSource::~MateriaSource(void)
{
    if (this->head)
        this->destroyObjs(this->head);
}

void MateriaSource::destroyObjs(Materia_Inventory *head_ref)
{

    Materia_Inventory *current = head_ref;
    Materia_Inventory *nxt = nullptr;

    while (current)
    {
        nxt = current->next;
        delete (current->Materia);
        delete (current);

        current = nxt;
    }
    head_ref = nullptr;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{

    std::cout << "MateriaSource copy constructor called.\n";

    if (this == &rhs)
        return *this;

    if (this->head)
        this->destroyObjs(this->head);
    this->head = nullptr;
    this->tail = nullptr;

    Materia_Inventory *tempHead;

    if ((tempHead = rhs.head))
    {
        this->push(tempHead->Materia->clone()); // Upon copy construction or assignation, the copy must be deep.
        while (tempHead->next)
        {
            tempHead = tempHead->next;
            this->push(tempHead->Materia->clone());
        }
    }
    return (*this);
}

void MateriaSource::push(AMateria *Materia)
{
    // std::cout << "-----pushing-------\n";
    if (Materia)
    {
        Materia_Inventory *newMateria;

        if (!(newMateria = new Materia_Inventory))
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
            std::cout << "Inventory is full!\n";
            delete newMateria;
        }
    }

    // printList(this->head);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (materia == nullptr)
        return;
    this->push(materia);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{

    Materia_Inventory *temp;

    temp = this->head;
    while (temp)
    {
        if (temp->Materia->getType().compare(type) == 0)
        {
            // std::cout << "  FOUND ***> = " <<  temp->Materia->getType() << "\n";   
            return (temp->Materia->clone());
        }
        temp = temp->next;
    }
    std::cout << "\nInvalid Type \n";
    return (nullptr);
}
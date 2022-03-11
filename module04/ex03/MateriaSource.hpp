#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

class Materia_Inventory
{
public:
    int id;
    AMateria *Materia;
    Materia_Inventory *next;
};

class MateriaSource : public IMateriaSource
{
private:
    Materia_Inventory *head;
    Materia_Inventory *tail;

public:
    MateriaSource(void);
    MateriaSource(MateriaSource const &);
    virtual ~MateriaSource(void);
    MateriaSource &operator=(MateriaSource const &);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);

    void destroyObjs(Materia_Inventory *head_ref);
    void push(AMateria *Materia);
    void shiftList(int);
    //  void    garbageCollector(Materia_Inventory *toRemove);
};

#endif
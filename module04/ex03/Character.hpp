
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class MateriaInventory
{
public:
    int id;
    AMateria *Materia;
    MateriaInventory *next;
};

class Character : public ICharacter
{
private:
    std::string _name;
    MateriaInventory *head;
    MateriaInventory *tail;
    // MateriaInventory *trash;
    // MateriaInventory *trashTail;

public:
    Character(void);
    Character(std::string const &name);
    Character(Character const &);
    virtual ~Character(void);

    Character &operator=(Character const &);
    std::string const &getName(void) const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    void destroyObjs(MateriaInventory *head_ref);
    void push(AMateria *Materia);
    void shiftList(int);
    // void    garbageCollector(MateriaInventory *toRemove);
};

#endif
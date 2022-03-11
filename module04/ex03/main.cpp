#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

int main(void)
{
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter *bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n\n------------------------------------\n\n";

    {
        IMateriaSource *src = new MateriaSource();
        AMateria *cure = new Cure();
        ICharacter *me = new Character("me");
        AMateria *tmp;
        AMateria *tmp2;
        ICharacter *bob = new Character("bob");
        Ice ice2;
        Cure cure2;
        AMateria *cure3;
        Cure cure4;

        std::cout << "XP of " << cure->getType() << " : " << cure->getXP() << std::endl;
        cure->use(*bob);
        std::cout << "XP of " << cure->getType() << " : " << cure->getXP() << std::endl;
        cure->use(*bob);
        std::cout << "XP of " << cure->getType() << " : " << cure->getXP() << std::endl;

        cure3 = cure->clone();
        std::cout << "XP of " << cure3->getType() << " : " << cure3->getXP() << std::endl;
        cure4.use(*bob);
        cure2 = cure4;
        std::cout << "XP of " << cure2.getType() << " : " << cure2.getXP() << std::endl;

        AMateria *ice11 = new Ice();
        AMateria *cure22 = new Cure();
        AMateria *ice22 = new Ice();

        src->learnMateria(cure);
        src->learnMateria(ice11);
        src->learnMateria(cure22);
        src->learnMateria(ice22);

        tmp = src->createMateria("cure");
        if (tmp == nullptr)
            std::cerr << " NOT FOUND \n";
        else
            std::cout << "XP of " << tmp->getType() << " : " << tmp->getXP() << std::endl;

        me->equip(tmp);

        src->learnMateria(&cure2); // <---- Inventory is full!
        src->learnMateria(&cure2); // <---- Inventory is full!
        src->learnMateria(cure3);  // <---- Inventory is full!
        src->learnMateria(&ice2);  // <---- Inventory is full!

        std::cout << "=============================" << std::endl;

        tmp2 = src->createMateria("cure");
        me->equip(tmp2);
        me->equip(ice2.clone());
        me->equip(cure2.clone());
        me->equip(cure3);
        me->equip(tmp);
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->use(4, *bob);
        me->use(-1, *bob);
        me->use(100, *bob);

        std::cout << "=====Character Inventory=====" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            me->use(i, *me);
        }
        std::cout << "=============================" << std::endl;

        std::cout << "XP of " << cure->getType() << " : " << cure->getXP() << std::endl;
        cure->use(*bob);
        std::cout << "XP of " << cure->getType() << " : " << cure->getXP() << std::endl;
        cure->use(*bob);
        std::cout << "XP of " << cure->getType() << " : " << cure->getXP() << std::endl;
        delete cure3;
        delete bob;
        delete me;
        delete src;
    }

    return (0);
}

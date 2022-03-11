
#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main(void)
{
    {
        ISpaceMarine *bob = new TacticalMarine;
        ISpaceMarine *jim = new AssaultTerminator;
        ISquad *vlc = new Squad;
        vlc->push(bob);
        vlc->push(jim);
        for (int i = 0; i < vlc->getCount(); ++i)
        {
            ISpaceMarine *cur = vlc->getUnit(i);
            cur->battleCry();
            cur->rangedAttack();
            cur->meleeAttack();
        }
        delete vlc;
    }

    std::cout << "\n***************************************\n" << std::endl;

    {
        // create squad
        std::cout << "-------- create squad -----\n";
        Squad *squad = new Squad;
        ISpaceMarine *bob = new TacticalMarine;
        ISpaceMarine *jim = new AssaultTerminator;

        squad->push(bob);
        squad->push(jim);

        std::cout << " -----copy constructor ----- \n";

        // test copy constructor
        Squad *squadCopy = new Squad(*squad);
        ISpaceMarine *jerry = new TacticalMarine;
        ISpaceMarine *jon = new AssaultTerminator;

        squadCopy->push(jerry);
        squadCopy->push(jon);

        std::cout << " squad has: " << squad->getCount() << " units." << std::endl;
        std::cout << "copied squad has: " << squadCopy->getCount() << " units." << std::endl;

        //test assignation operator
        std::cout << "---" << std::endl;
        *squadCopy = *squad;

        std::cout << " squad has: " << squad->getCount() << " units." << std::endl;
        std::cout << "copied squad has: " << squadCopy->getCount() << " units." << std::endl;
    }

    return 0;
}
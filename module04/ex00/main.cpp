
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Monkey.hpp"
#include "Macaque.hpp"

int main()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    

    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);

    std::cout << "\n    *** Other Victim **\n\n";

    Monkey Caesar("Caesar");
    std::cout << Caesar;
    // robert.polymorph(jim);
    robert.polymorph(Caesar);

     std::cout << "\n    *** Other Victim **\n\n";

    Macaque Macaque("Macaque");
    std::cout << Macaque;
    // robert.polymorph(jim);
    robert.polymorph(Macaque);

     std::cout << "\n   *** Destruction ** \n\n";
    return 0;
}
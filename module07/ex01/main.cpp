#include "iter.hpp"

int main(void)
{
        size_t len = 3;

        int arrInt[3] = {1, 2, 3};
        float arrFloat[3] = {1.1f, 2.1f, 3.1f};
        std::string arrString[3] = {"aaaa", "bbbb", "cccc"};

        std::cout << "\n *** Test Integer ***\n\n";
        iter(arrInt, len, print);
        std::cout << "\n";
        iter(arrInt, len, incr);
        iter(arrInt, len, print);

        std::cout << "\n\n";

        std::cout << " *** Test Float ***\n\n";
        iter(arrFloat, len, print);
        std::cout << "\n";
        iter(arrFloat, 3, incr);
        iter(arrFloat, len, print);

        std::cout << "\n\n";

        std::cout << " *** Test String ***\n\n";
        iter(arrString, len, print);
        std::cout << "\n";
        iter(arrString, 3, to_Upper);
        iter(arrString, len, print);

        return 0;
}

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
    Array<std::string> arrayOfStrings(3);
    Array<int> arrayOfIntegers(3);

    for (int i = 0; i < 3; i++)
    {
        arrayOfStrings[i] = "string";
        arrayOfIntegers[i] = i;
    }

    std::cout << " ******* Display *******\n\n";

    arrayOfStrings.displayArray();
    std::cout << "\n\n";

    arrayOfIntegers.displayArray();
    std::cout << "\n\n";

    std::cout << " ******* Modify *************\n\n";

    arrayOfStrings[arrayOfStrings.size() - 1] = "last";
    arrayOfIntegers[arrayOfIntegers.size() - 1] = 42;

    arrayOfStrings.displayArray();
    std::cout << "\n\n";

    arrayOfIntegers.displayArray();
    std::cout << "\n\n";

    std::cout << " ******* Test copy constructor ***\n\n";

    Array<std::string> copyArrayOfStrings(arrayOfStrings);
    Array<int> copyArrayOfIntegers(arrayOfIntegers);

    copyArrayOfStrings[0] = "first";
    copyArrayOfIntegers[0] = 13;

    copyArrayOfStrings.displayArray();
    std::cout << "\n\n";

    copyArrayOfIntegers.displayArray();
    std::cout << "\n\n";

    std::cout << " ******* Test Invalid Index **\n\n";

    try
    {
        arrayOfStrings[-1] = "Exception";
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << "\n\n";
    }

    return (0);
}

/*
#define MAX_VAL 750
int main(int, char **)
{
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return 0;
}
*/
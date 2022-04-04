
#include "MyClass.hpp"

int main()
{
    srand(time(nullptr));

    Base *b1 = generate();
    Base *b2 = generate();

    std::cout << "\n" << std::endl;

    std::cout << "=== cast to pointer ===" << std::endl;
    identify(b1);
    identify(b2);

    std::cout << "\n" << std::endl;

    std::cout << "=== cast to reference ===" << std::endl;
    identify(*b1);
    std::cout << std::endl;
    identify(*b2);

    delete b1;
    delete b2;

    return (0);
}
#include <iostream>

struct Employee
{
    int id;
    int age;
    double wage;
};

void printEmployee(Employee& emp, std::string name) // note pass by reference here
{
	std::cout << "	" + name << "\n";
    std::cout << "ID:   " << emp.id << '\n';
    std::cout << "Age:  " << emp.age << '\n';
    std::cout << "Wage: " << emp.wage << '\n';
	std::cout << "-------------------\n";
emp.id = 1000000;
	std::cout << "  " + name << "\n";
std::cout << "ID:   " << emp.id << '\n';
std::cout << "Age:  " << emp.age << '\n';
std::cout << "Wage: " << emp.wage << '\n';
std::cout << "-------------------\n";

}

int main()
{
    Employee joe = { 14, 32, 24.15 };
    Employee frank = { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(joe, "joe");

    //std::cout << '\n';
	std::cout << "IddddD:   " << frank.id << '\n';

    // Print Frank's information
    printEmployee(frank, "frank");

    return 0;
}

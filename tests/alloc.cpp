#include <iostream>

int main()
{
int *value = new (std::nothrow) int[10] ; // ask for an integer's worth of memory
delete[] value;
value = nullptr;
if (!value) // handle case where new returned null
{
    // Do error handling here
    std::cerr << "Could not allocate memory\n";
}
else{
	std::cout << "allocated \n";
	delete[] value;
	value = nullptr;
}
}

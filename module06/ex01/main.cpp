
#include<iostream>

# define RESET			"\033[0m"
# define GREEN			"\033[32m"

struct Data 
{
    char	isChar;
	int		isInt;
	float	isFloat;
};

uintptr_t		serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*			deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int				main(void)
{
	Data		data;
	Data*		dataRevPtr;
	uintptr_t	ptrHolder;

	data.isChar = 'A';
	data.isInt = 2000;
	data.isFloat = 2000.100;

	std::cout << "addr of the Struct = " << GREEN << &data << RESET << std::endl;

	std::cout << "\n\n";

	std::cout << "before reinterpret_cast : " << std::endl;
		std::cout << "	data.isChar = " << data.isChar << std::endl;
		std::cout << "	data.isInt  = " << data.isInt  << std::endl;
		std::cout << "	data.isFloat = " << data.isFloat << std::endl;

	std::cout << "\n\n";

	ptrHolder = serialize(&data);
	std::cout << "Data pseudo-Serialization, ptrHolder = " << ptrHolder  << std::endl;

	dataRevPtr = deserialize(ptrHolder);

	std::cout << "\n\n";

	std::cout << "after Reversing the Process , dataRevPtr =  " << GREEN << dataRevPtr << RESET << std::endl;
		std::cout << "	dataRevPtr->isChar = " << dataRevPtr->isChar << std::endl;
		std::cout << "	dataRevPtr->isInt  = " << dataRevPtr->isInt  << std::endl;
		std::cout << "	dataRevPtr->isFloat = " << dataRevPtr->isFloat << std::endl;
	return (0);
}
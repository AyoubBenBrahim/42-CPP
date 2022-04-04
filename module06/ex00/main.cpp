
#include "Conversion.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "usage:\n	./ScalarConversion input\n";
		return -1;
	}
	try
	{
		Conversion conversion(argv[1]);
		conversion.printOrchestration();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

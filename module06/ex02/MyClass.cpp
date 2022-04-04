
#include "MyClass.hpp"

Base::~Base(void)
{
}

Base *generate(void)
{
	Base *base;
	int rndomNbr;

	rndomNbr = rand() % 3;
	switch (rndomNbr)
	{
	case 0:
		std::cout << "Generated class A" << std::endl;
		base = new A;
		break;
	case 1:
		std::cout << "Generated class B" << std::endl;
		base = new B;
		break;
	default:
		std::cout << "Generated class C" << std::endl;
		base = new C;
		break;
	}

	return base;
}

void    identify(Base* p)
{
	Base *basePTR = p;

	A *instanceA = dynamic_cast<A*>(basePTR);
	B *instanceB = dynamic_cast<B*>(basePTR);
	C *instanceC = dynamic_cast<C*>(basePTR);

	if (instanceA != nullptr)
		std::cout << "A" << std::endl;
	else if (instanceB != nullptr)
		std::cout << "B" << std::endl;
	else if (instanceC != nullptr)
		std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
        (void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast exp)
	{
        std::cout<<"A bad cast\n";
	}
	try 
	{
		B& b = dynamic_cast<B&>(p);
        (void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast exp)
	{
        std::cout<<"B bad cast\n";
	}
	try 
	{
		C& c = dynamic_cast<C&>(p);
        (void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast exp)
	{
        std::cout<<"C bad cast\n";
	}
}
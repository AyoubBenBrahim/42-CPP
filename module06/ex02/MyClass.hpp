#ifndef CLASS_HPP
# define CLASS_HPP

#include <iostream>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base    *generate(void);

/*

The value of a failed cast to pointer type is the null pointer value of the required result type. 
A failed cast to reference type throws bad_cast.

the diff is you can have a null pointer, but not a null reference - any reference has to be bound to an object.

So when dynamic_cast for a pointer type fails it returns a null pointer and the caller can check for that, but when it fails 
for a reference type it can't return a null reference, so an exception is the only reasonable way to signal a problem.
https://stackoverflow.com/questions/1276847/difference-in-behavior-while-using-dynamic-cast-with-reference-and-pointers

*/
void    identify(Base* p);
void    identify(Base& p);

#endif
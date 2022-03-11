
A virtual function is a member function which is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function. 

    Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
    They are mainly used to achieve Runtime polymorphism
    Functions are declared with a virtual keyword in base class.
    The resolving of function call is done at runtime.


   1/ Virtual functions should be accessed using pointer or reference of base class type to achieve runtime polymorphism.
2/ The prototype of virtual functions should be the same in the base as well as derived class.
3/ They are always defined in the base class and overridden in a derived class.

*****

 the derived class’s function is called using a base class pointer.
The idea is that virtual functions are called according to the type of the object instance pointed to or referenced, not according to the type of the pointer or reference.
In other words, virtual functions are resolved late, at runtime.

*****

to ensure that the function is overridden


a virtual function is used in the base class in order to ensure that the function is overridden. This especially applies to cases where a pointer of base class points to an object of a derived class.



Derived derived1;
    Base* base1 = &derived1;

    // calls function of Base class
    base1->print();

Later, if we create a pointer of Base type to point to an object of Derived class and call the print() function, it calls the print() function of the Base class.

In other words, the member function of Base is not overridden.

In order to avoid this, we declare the print() function of the Base class as virtual by using the virtual keyword.

So, this function is overridden even when we use a pointer of Base type that points to the Derived object derived1.

*****

Static Binding/Static linking

As we saw above, C++ uses static binding by default to determine which member
function to call for a derived class.

Alternatively, in dynamic binding, an object’s
contents determine which member function is called. To specify that a member

function should use dynamic binding, the keyword “virtual” is added to the func-
tion’s declaration.

The decision as to which function to call is made at run-time, hence the
name dynamic binding.

Dynamic binding is a powerful technique, since it allows us to create an object,
such as the array pp above, whose behavior varies depending on its contents. This
technique is fundamental to the concept of polymorphism,

Virtual Destructors

There is no such thing as a virtual constructor. Such a concept does not make any
sense. Virtual destructors, however, are very important. In our array example, since
we store objects of both types Person and Student in the array, it is important that
the appropriate destructor be called for each object. However, if the destructor is

nonvirtual, then only the Person destructor will be called in each case. In our ex-
ample, this choice is not a problem. But if the Student class had allocated memory

dynamically, the fact that the wrong destructor is called would result in a memory
leak

to be safe, when defining any virtual
functions, it is recommended that a virtual destructor be defined as well. This
destructor may do nothing at all, and that is fine. It is provided just in case a
derived class needs to define its own destructor. This principle is encapsulated in
the following rule of thumb:

If a base class defines any virtual functions, it should define a virtual de-
structor, even if it is empty.


Chap2: OO design / Data structures and algorithms in C++
Book by Michael T. Goodrich


**********************************

Polymorphism

the ability of a variable to take different types.
Polymorphism means same action but different behaviors.
****
Polymorphism is the capability of having the same function name invoke different responses, based on the object used in making the function call. It can be accomplished with override functions or virtual functions.

Polymorphism is typically applied in C++ using pointer variables. In particular, a variable p declared to be a pointer to some class S implies that p can point to any object belonging to any derived class T of S.

Now consider what happens if both of these classes define a virtual member function a, and let us consider which of these functions is called when we invoke p->a(). Since dynamic binding is used, if p points to an object of type T, then it invokes the function T::a. In this case, T is said to override function a from S.
Alternatively, if p points to an object of type S, it will invoke S::a.

Polymorphism such as this is useful because the caller of p->a() does not have to know whether the pointer p refers to an instance of T or S in order to get the a function to execute correctly. A pointer variable p that points to a class object that has at least one virtual function is said to be polymorphic. That is, p can take many
forms, depending on the specific class of the object it is referring to. This kind of functionality allows a specialized class T to extend a class S, inherit the “generic” functions from class S, and redefine other functions from class S to account for specific properties of objects of class T.

We can define classes that inherit generic member variables and functions

and can then define new, more specific variables and functions that deal with spe-cial aspects of objects of the new class. For example, suppose that we defined a

generic class Person and then derived three classes Student, Administrator, and Instructor. We could store pointers to all these objects in a list of type Person*.
When we invoke a virtual member function, such as print, to any  lement of the list, it will call the function appropriate to the individual element’s type.

Chap2: OOdesign / Data structures and algorithms in C++
Book by Michael T. Goodrich

*******

As this output shows, the same result is obtained, no matter which object type calls the f2() function, because the derived class doesn’t have an override of the base class’s f2() function. Therefore, both calls to f2() result in the base class’s f2() function being called.
After the base class’s f2() function is called, it always calls the base class’s version of f1() rather than the derived class’s override version. This behavior is caused by a process referred to as function binding. In normal function calls, static binding is used, meaning the determination of which function is called is made at compile time. Therefore, when the compiler first encounters the f1() function in the base class, it makes the determination that whenever f2() is called, from either a base or derived class object, it subsequently calls the base class’s f1() function.
In place of static binding, say you want to use a binding method capable of determining which function should be called at runtime, based on the object type making the call. This type of binding, referred to as dynamic binding, is achieved in C++ with virtual functions. A virtual function tells the compiler to create a pointer to a function, but not fill in the pointer’s value until the function is actually called. Then at runtime, based on the object making the call, the appropriate function address is used.
Creating a virtual function is easy—simply place the keyword virtual before the function’s return type in the class declaration section. For example, examine Program 12.3, which is identical to Program 12.2, except for the virtual declaration of the f1() function.

In static binding, the determination of which function is called is made at compile time. In dynamic binding, the determination is made at runtime.
‫-----‬

the f2() function now calls different versions of the overloaded f1() function based on the object type making the call. Basing the selection on the object making the call is the classic definition of polymorphic behavior and is caused by the dynamic binding imposed on f1() because it’s a virtual function.


After a function is declared as virtual, it remains virtual for the next derived class, with or without a virtual declaration in the derived class. Therefore, the second virtual declaration in the derived class isn’t strictly necessary but should be included for clarity and to make sure any subsequently derived classes inherit the function correctly.
In the inheritance diagram in Figure 12.5, class C is derived from class B and class B is derived from class A.1 In this situation, if the f1() function is virtual in class A but not declared in class B, it isn’t virtual in class C. The only other requirement is that after a function has been declared as virtual, the return type and parameter list of all subsequent derived class override versions must be the same.


A first book of C++, 4th ed chap 12 p 549

***************************

Interfaces


For two objects to interact, they must “know” about each other’s member func- tions. To enforce this “knowledge,” the object-oriented design paradigm asks that classes specify the application programming interface (API), or simply interface, that their objects present to other objects. 

An interface is a collection of function declarations with no data and no bodies. That is, the member functions of an interface are always empty. When a class implements an interface, it must implement all of the member functions declared in the interface.

---

An abstract class in C++ is a class that is used only as a base class for inheri- tance; it cannot be used to create instances directly. At first the idea of creating a class that cannot be instantiated seems to be nonsense, but it is often very important. For example, suppose that we want to define a set of geometric shape classes, say, Circle, Rectangle, and Triangle. It is natural to derive these related classes from a single generic base class, say, Shape. Each of the derived classes will have a virtual member function draw, which draws the associated object. The rules of inheritance require that we define such a function for the base class, but it is unclear what such a function means for a generic shape.
One way to handle this would be to define Shape::draw with an empty function body ({ }), which would be a rather unnatural solution. What is really desired here is some way to inform the compiler that the class Shape is abstract; it is not possible to create objects of type Shape, only its subclasses. In C++, we define a class as being abstract by specifying that one or more members of its functions are abstract, or pure virtual. A function is declared pure virtual by giving “=0” in place of its body. C++ does not allow the creation of an object that has one or more pure virtual functions. Thus, any derived class must provide concrete definitions for all pure virtual functions of the base class.

class Progression
 { // ...
virtual long nextValue() = 0;
// ...
};

As a result, the compiler will not allow the creation of objects of type Progres- sion, since the function nextValue is “pure virtual.” However, its derived classes, ArithProgression for example, can be defined because they provide a definition for this member function.


Data structures and algorithms in C++

***

Sometimes implementation of all function cannot be provided in a base class because we don’t know the implementation. Such a class is called abstract class

We cannot provide implementation of function draw() in Shape, but we know every derived class must have implementation of draw(). Similarly an Animal class doesn’t have implementation of move() (assuming that all animals move), but all animals must know how to move. We cannot create objects of abstract classes.

/ Pure Virtual Function
    virtual void show() = 0;

Geeks F Geeks

===========================

 the difference between a deep copy and a shallow copy

https://stackoverflow.com/questions/184710/what-is-the-difference-between-a-deep-copy-and-a-shallow-copy



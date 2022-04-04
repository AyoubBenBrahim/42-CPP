int Object::intValue() const throw(BadCast)   // cast to Integer
{
const Integer* p = dynamic cast<const Integer*>(this);
if (p == NULL)
 throw BadCast(IllegalattempttocasttoInteger); 
return p−>getValue();
}


========

    static_cast performs implicit conversions, the reverses of implicit standard conversions, and (possibly unsafe) base to derived conversions.

    reinterpret_cast converts one pointer to another without changing the address, or converts between pointers and their numerical (integer) values.

    reinterpret_casts are applicable in two scenarios:

    1* convert integer types to pointer types and vice versa
    2* convert one pointer type to another. The general idea I get is this is unportable and should be avoided.


    const_cast only changes cv-qualification; all other casts cannot cast away constness.

    dynamic_cast casts up and down class hierarchies only, always checking that the conversion requested is valid.

========

C++ provides an operation called a reinterpret cast, to cast between such unrelated types.
 This cast treats quantities as a sequence of bits and makes no attempt to intelligently convert the meaning of one quantity to another.

 ===

 https://www.youtube.com/playlist?list=PLRwVmtr-pp05motkiTlDIuU5ZfoRr-kWC

 https://stackoverflow.com/questions/1276847/difference-in-behavior-while-using-dynamic-cast-with-reference-and-pointers

 ===

 reinterpret_cast only guarantees that if you cast a pointer to a different type, 
 and then reinterpret_cast it back to the original type, you get the original value.
 https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast

 =====

 The value of a failed cast to pointer type is the null pointer value of the required result type. A failed cast to reference type throws bad_cast.

the diff is you can have a null pointer, but not a null reference - any reference has to be bound to an object.

So when dynamic_cast for a pointer type fails it returns a null pointer and the caller can check for that, but when it fails 
for a reference type it can't return a null reference, so an exception is the only reasonable way to signal a problem.
https://stackoverflow.com/questions/1276847/difference-in-behavior-while-using-dynamic-cast-with-reference-and-pointers
/*
Class types in non-type template parameters:-
- Classes can now be used in non-type template parameters. 
  Objects passed in as template arguments have the type const T,
  where T is the type of the object, and has static storage duration.

- Prior to C++20, non-type template parameters were restricted to:

    lvalue reference type (to object or to function);
    an integral type;
    a pointer type (to object or to function);
    a pointer to member type (to member object or to member function);
    an enumeration type;
    std::nullptr_t (since c++11)

- Now (C++20), this has been extended with support for:

    an floating-point type;
    a literal class type with the following properties:
    all base classes and non-static data members are public and non-mutable and
    the types of all bases classes and non-static data members are structural types or (possibly multi-dimensional) array thereof.

- From https://en.cppreference.com/w/cpp/language/template_parameters

- A type which satisfies one of the above definitions is considered to be a structural type.
*/

#include <iostream>
#include <stdint.h>     // uint32_t

struct NullOptT {} NullOpt;

/**
 * Literal class type.
 *
 * Represents an optionally provided `int`.
 */
struct OptionalInt {
    constexpr OptionalInt(NullOptT) {}
    constexpr OptionalInt(int value): has_value(true), value(value) {}
            
    const bool has_value = false;
    const uint32_t value {};
};

/**
 * Prints whether or not a value was provided for "maybe" WITHOUT branching :)
 */
template<OptionalInt maybe>
void Print() {
    if constexpr(maybe.has_value) {
        std::cout << "Value is: " << maybe.value << std::endl;
    } else {
        std::cout << "No value." << std::endl;
    }
}

// Note: implicit conversions are at play!
int main()
{
    Print<123>();     // Prints "Value is: 123"
    Print<NullOpt>(); // Prints "No value."
}

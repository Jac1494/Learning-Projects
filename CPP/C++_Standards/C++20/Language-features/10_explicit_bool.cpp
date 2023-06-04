/*
explicit(bool):-
- Conditionally select at compile-time whether a constructor is made explicit or not. 
  explicit(true) is the same as specifying explicit.
*/

#include <iostream>
struct foo {
  // Specify non-integral types (strings, floats, etc.) require explicit construction.
  template <typename T>
  explicit(!std::is_integral_v<T>) foo(T) {}
};

int main()
{
    foo a = 123; // OK
    //foo b = "123"; // ERROR: explicit constructor is not a candidate (explicit specifier evaluates to true)
    foo c {"123"}; // OK

    return 0;
}
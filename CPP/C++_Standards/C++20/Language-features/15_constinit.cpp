/*
constinit:-
- The constinit specifier requires that a variable must be initialized at compile-time.
*/

#include <iostream>

const char* g() { return "dynamic initialization"; }
constexpr const char* f(bool p) { return p ? "constant initializer" : g(); }
constinit const char* c = f(true); // OK
//constinit const char* d = f(false); // ERROR: `g` is not constexpr, so `d` cannot be evaluated at compile-time.

int main()
{
    //constinit const char* c1 = f(true); // error: local variable cannot be declared 'constinit'
    return 0;
}
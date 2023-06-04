/*
Immediate functions:-
- In C++20, an immediate function is a function where every call to the function either directly or indirectly produces a compile-time constant expression.
- These functions are declared by using a consteval keyword before their return type.
- The consteval function is the same as constexpr function except that if the call 
  to a consteval function doesn’t evaluate to a compile-time constant expression, then the program gives an error while it is not so in the case of a constexpr function.
*/

#include <iostream>
consteval int sqr(int n) {
  return n * n;
}

int main()
{

constexpr int r = sqr(100); // OK
int x = 100;
//int r2 = sqr(x); // ERROR: the value of 'x' is not usable in a constant expression
                 // OK if `sqr` were a `constexpr` function
    return 0;
}
/*
User-defined literals for standard library types:-
- New user-defined literals for standard library types, including new 
  built-in literals for chrono and basic_string.
- These can be constexpr meaning they can be used at compile-time. 
  Some uses for these literals include compile-time integer parsing, 
  binary literals, and imaginary number literals.
*/

#include<iostream>
#include<chrono>
using namespace std;

// Check with -std=c++11 will get error

int main(){

   auto hours = 24h;    // h -> hours
   cout << hours.count() << "\n"; // 24  
   cout << std::chrono::duration_cast<std::chrono::minutes>(hours).count() << "\n"; // 1440

   return 0;
}
/*
Relaxing constraints on constexpr functions:-
- constexpr function bodies could only contain a very limited set of syntaxes, 
  including (but not limited to): typedefs, usings, and a single return statement. 
- In C++14, the set of allowable syntaxes expands greatly to include the most 
  common syntax such as if statements, multiple returns, loops, etc..
*/

#include<iostream>
using namespace std;

// Check with -std=c++11 will get warning
constexpr int factorial(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main(){

   cout << factorial(5); // 120

   return 0;
}
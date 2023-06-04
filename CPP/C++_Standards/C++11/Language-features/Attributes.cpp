/*
Attributes:-
- Attributes provide a universal syntax over __attribute__(...), __declspec, etc.
- https://www.geeksforgeeks.org/attributes-in-c/
*/
#include<iostream>
using namespace std;

// `noreturn` attribute indicates `f` doesn't return.
[[ noreturn ]] void f() {
  throw "error";
}

int main(){

    return 0;
}
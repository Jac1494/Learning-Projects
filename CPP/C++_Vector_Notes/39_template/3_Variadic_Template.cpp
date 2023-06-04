#include<iostream>
using namespace std;

/*
Variadic template:-
-----------------
- So far we have seen function templates that take a fixed number of arguments. 
- There are also templates that take a variable number of arguments. 
- These function templates are called variadic templates. Variadic templates are one of the newest features of C++11.
- Variadic templates take a variable number of arguments that are type-safe and the arguments are resolved at compile-time.
*/

template < class T >
T aggregate( T x ){ return x;}

template < class T , class ... Args>
T aggregate( T x , Args ... args){  // Check 2nd argument
    return x + aggregate(args...);
}

int main(){

  
  cout << "========================="<< "\n";
  cout << "aggregate of variable is "<< aggregate(11,22,33) << "\n";  
  cout << "aggregate of variable is "<< aggregate(1.1,2.2,3.3) << "\n";  
  string S1 = "A",S2 = "B", S3 = "C";
  cout << "aggregate of variable is "<< aggregate(S1,S2,S3) << "\n";  
  cout << "========================="<< "\n";

  return 0;
}

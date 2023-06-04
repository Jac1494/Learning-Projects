/*
Explicit Keyword:-
- In C++ , explicit is a keyword used before constructors and is defined as 
  making the constructor not conduct any implicit conversion by specifying
  the keyword explicit.
- This is defined to avoid few implicit conversion when a class contain a 
  single argument constructor, which usually the compiler considers it as
  a conversion constructor or implicit conversion, which may , in turn , lead to some 
  unwanted outputs and avoid such results. 
- We have to define such construcotrs with an explicit keyword before the 
  constructor name.
- In general, the explicit constructor is declared where we cannot use 
  implicit constructor , and such explicit constructor always have single
  or more arguments.  
*/

#include<iostream>
using namespace std;

class A {
    int x = 0;
public:
  
  A(const int & value): x(value){}
  // If we use explicit constructor above then it will give error
  // Because it will stop implicit type conversion.
  //explicit A(const int & value): x(value){}

  int getvalue() const{
    return x;
  }
};

int main(){
  
  A ob = 'a';
  cout << "Value of x is => " << ob.getvalue();  // 97
  return 0;
}

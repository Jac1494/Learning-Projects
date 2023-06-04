/*
Static member of class:-
- static member of class is part of class but not part of object.
- Only one copy of static variable is created for entire class, sinece it
  is shared by all the objects of that class.
- Function overloading is not possible if one function is static and
  other one is non static.
- static member function can access only static members of the same classe.
- static member function can call using by class name.
  example:- classname::functionname();
  
Note:-
- Storage class not there in structure because , it's need to store variable in 
  quantizies memory location.
*/

#include<iostream>
using namespace std;
int z = 9;

class A {

  public:
  int x=1;
  static int y;
  void no_static_method(){
     x=2;
     y=3; // static variable can be allowed in non static method
  }
  static void static_method(){
     // x=9;  this will give error static method only allows static members inside the function
     cout << y <<"\n"; // 11
  }
  
  // void static_method(){} -> static and non-static method can't overload
};
int A::y=11;  // We need to assign value this way 

int main(){
  A a;
  // Below both way we can able to access static 
  cout << A::y <<"\n"; // 11
  cout << a.y <<"\n"; // 11  // static members are not part of class but still we are able to use this.
  A::static_method();

  return 0;
}

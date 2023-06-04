#include<iostream>
using namespace std;

/*
Pure Virtual Function:-
- A virtual function that is declared but not defined in a base clasee
  is referred to as a pure virtual function.
- Syntax:-
  virtual returntype functionname(arg ...) = 0;    OR
  returntype virtual functionname(arg ...) = 0;

Abstract class:-
- If a class contains at least one pure virtual function is called as abstract class.
- If a vitual function declared as pure, it must be redefined in each 
  derived class, else compilation of the progream is unsucceful.

NOTE:-
- A class having pure virtual function can't be used to instantiate
  object of its own. OR 
  we can say that, we can't able to create object of abstract class.

*/
class A {

  public:
  A(){}
  ~A(){}

  virtual void fun(void) = 0;
};

class B: public A {    

  public:
  B(){}
  ~B(){}

  void fun(void)
  {
    cout << "Fun method in class B" << "\n" ;
  }
};

int main(){

  A *p;
  B b;

  // Call Class B
  p=&b;
  p->fun();  // Fun method in class B

  return 0;
}


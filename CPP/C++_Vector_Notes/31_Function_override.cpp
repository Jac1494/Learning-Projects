#include<iostream>
using namespace std;

// Function override:-

class A {

  public:
  A(){}
  ~A(){}

/*
- If below method is not virtual it will call method of class A for both call,
 Because pointer is class.
- It will resolve at Runtime.
- We need pointer for this case.
*/

  virtual void fun(void)
  {
    cout << "Fun method in class A" << "\n" ;
  }
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
  A a;
  B b;

  // Call Class A 
  p=&a;
  p->fun();

  // Call Class B
  p=&b;
  p->fun();

  return 0;
}


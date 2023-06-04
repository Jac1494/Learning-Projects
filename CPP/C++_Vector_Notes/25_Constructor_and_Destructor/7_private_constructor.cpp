#include<iostream>
using namespace std;

class A {

  // We are make private constructor to avoid creating object.
     
  A(){
    cout << "Constructor of A\n";
  }
  public:
  // But we have inherited this so it will give error in base class
  // So we have created paramaterzed constructor.
  A(int x){}
  ~A(){
    cout << "Destructor of A\n";
  }
};

class B: public A {

  public:
  B():A(11){
    cout << "Constructor of B\n";
  }
  ~B(){
    cout << "Destructor of B\n";
  }
};

int main(){

  B b;
  return 0;
}
/*
Constructor of B
Destructor of B
Destructor of A
*/

#include<iostream>
using namespace std;

/*
Virtual Table:-
- To implement virtual functions, C++ uses a special form of late binding
  known as the virtual table, It is created in compile time.
- The virtual table is a lookup table of address only for the virtual function
  in corresponding class to resolve the function with the proper function calls.  
  
Rules for virtual function.
1. It must be not static members.
2. It will access by using pointer to object.
3. It can be friend of another class.
4. Constructor can't be virtual but destructor can be made.
5. Base class pointer can refer derived class objects. But reverse is not possible.
6. It should be declared in public section.

Why we need virtual destructor ..?
-  Deleting a derived class object using a pointer to a base class that has a
non virtual destructor results is undefined behaviour to correct this situation
, the base class be defined with a virtual destructor.

Why virtual function must be non-static ..?
- Static is not part of object but part of class. And virtual call only object
  is creared then it is binded at Runtime, where static binded at compile time.
*/

class A {

  public:
  A(){ cout << "Constructor A\n";}
  virtual ~A(){ cout << "Destructor A\n";} 
     // If not mark virtual derived class constructor will not call
};

class B: public A {    

  public:
  B(){ cout << "Constructor B\n";}
  ~B(){ cout << "Destructor B\n";}
};

int main(){

  A *b = new B();  
  delete b;
  
  return 0;
}


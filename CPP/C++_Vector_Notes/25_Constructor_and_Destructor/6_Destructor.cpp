/*
Destructor:-
- A destructor is special member function of a class which is invoked
  automatically to destroy the object when the scope of the object
  is completed.

- Syntax:-
  ~classname(){}

- More then one destructor is not possible in class.
- It will invoked automatically , But we need manully free the
  dynamically allocated memory.

Characteristics:-
- It don't have a return type, not even void.
- It can't declared as static , const or volatile.
- It must be declared in the public section, if the object 
  are getting created outside class.  
- It is necessory that a destructor use a delete expression to 
  deallocate the memory , If constructor in progream uses the
  new expression for allocation the memory.
- It can be virtual.
- Destructor is called in the reverse order of its constructor
  invocation.
*/

#include<iostream>
#include<cstring>
using namespace std;

class A {
 
  int x,y;
  public:
  A(){
    cout << "Constructor" << "\n";
  }
  ~A(){
    cout << "Destructor" << "\n";
  }
};

int main(){
  
  A a;
  return 0;
}

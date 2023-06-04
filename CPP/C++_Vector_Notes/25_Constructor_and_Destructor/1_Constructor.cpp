/*
Constructor and Destructor:-
- "A constructor is a special member function of a class which is invoked automatically when an object
  of the same class is created. the object gets automatically intialized by the constructor."
- The C++ provides a mechanism to initilize an object/data during its creation and destroy the object when it is no 
  longer needed by using special member functions knowns as constructor and destructor.
- When object is created than constrcutor will invoke and life of object end that destructor will call for object.
- for each object constructor and destrcutor will call.

- Syntax:-
  classname::classname(arg...){}

Characteristics:-
- It has same name as the class to which it belongs.
- It don't have a return type, not even void.
- It must be declared in the public section, if the object are getting created outside class.  (// Check Singleton once)
- Every object of the class containing a constructor is initialized.
- Address of constructor can't be reffered.
- A constructor can have the default arguments.
- constructor can be overloaded.
- constructor can't be inherited althrough a derived class can call the base class constructor. // Check
- constructor can't be virtual.

- If the user providing explicite constructor in a class then default constructor ignored by the compiler.

Types of constructors:-
1. Default constructor
2. Parameterized constructor
3. copy constructor
4. dynamic constructor

Default member of class:-
1. Default constructor
2. copy constructor
3. Destructor 
4. Assignment operator overload function.

Why constructor don't have return value but parameters ..?
- Constructor are called when object is created and there is not situation where we need to return 
  a value at time of object creation. But we need initilzed value with different values at
  the time of creation.
  
*/

#include<iostream>
using namespace std;

class A {
 
  public:
  A(){      // No argument
      cout << "Default constructor\n";
  }
  A(int x){ // One and more argument
      cout << "Paramaterize constructor\n";
  }
  A(A& ob){
      cout << "Copy constructor\n";
  }
  ~A(){
      cout << "Destructor\n";
  }
};


int main(){
  
  A a,b(1);
  A c=a;
}
/*
Default constructor
Paramaterize constructor
Copy constructor
Destructor
Destructor
Destructor
*/  

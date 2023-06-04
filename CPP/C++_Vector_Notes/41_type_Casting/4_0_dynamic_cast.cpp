/*
Dynamic Cast:-
- A cast is an operator that converts data from one type to another type. 
  In C++, dynamic casting is mainly used for safe downcasting at run time. 
  To work on dynamic_cast there must be one virtual function in the base class.
- A dynamic_cast works only polymorphic base class because it uses this information 
  to decide safe downcasting.

Syntax:
- dynamic_cast <new_type>(Expression)

1) Downcasting:- 
- Casting a base class pointer (or reference) to a derived class pointer (or reference) 
  is known as downcasting. In figure 1  casting from the Base class 
  pointer/reference to the “derived class 1” pointer/reference showing downcasting 
  (Base ->Derived class).

2) Upcasting:-
- Casting a derived class pointer (or reference) to a base class pointer (or reference) 
  is known as upcasting. In figure 1 Casting from Derived class 2 pointer/reference to 
  the “Base class” pointer/reference showing Upcasting (Derived class 2 -> Base Class).

*/

// C++ program demonstrate if there
// is no virtual function used in
// the Base class
#include <iostream>
using namespace std;

// Base class declaration
class Base {
	void print()
	{
		cout << "Base" << endl;
	}
};

// Derived Class 1 declaration
class Derived1 : public Base {
	void print()
	{
		cout << "Derived1" << endl;
	}
};

// Derived class 2 declaration
class Derived2 : public Base {
	void print()
	{
		cout << "Derived2" << endl;
	}
};

// Driver Code
int main()
{
	Derived1 d1;

	// Base class pointer hold Derived1
	// class object
	Base* bp = dynamic_cast<Base*>(&d1);

	// Dynamic casting
//	Derived2* dp2 = dynamic_cast<Derived2*>(bp);  // Error (Base member function should be virtual)
//	if (dp2 == nullptr)
//		cout << "null" << endl;

	return 0;
}

#include<iostream>
using namespace std;
 
/*
1. Encapsulation
- Encapsulation in C++ is defined as the wrapping up of data and information in a single unit. In Object Oriented Programming, 
Encapsulation is defined as binding together the data and the functions that manipulate them.

- In C++, encapsulation can be implemented using classes and access modifiers.

Features of Encapsulation:-
-------------------------
1. We can not access any function from the class directly. We need 
   an object to access that function that is using the member variables of that class. 
2. The function which we are making inside the class must 
   use only member variables, only then it is called encapsulation.
3. If we don’t make a function inside the class which is using 
   the member variable of the class then we don’t call it encapsulation.
4. Increase in the security of data
5. It helps to control the modification of our data members.

*/

// C++ program to demonstrate
// Encapsulation 
#include <iostream>
using namespace std;

class Encapsulation {
private:
	// Data hidden from outside world
	int x;

public:
	// Function to set value of
	// variable x
	void set(int a) { x = a; }

	// Function to return value of
	// variable x
	int get() { return x; }
};

// Driver code
int main()
{
    Encapsulation obj;
    obj.set(5);
    cout << obj.get() << '\n';      // 5
    return 0;
}



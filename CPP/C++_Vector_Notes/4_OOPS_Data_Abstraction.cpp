/*
Data Abstraaction:-
- It refers to the act of representing essential features and hiding the background details.

- There are thress types of abstraction level
1. Public
2. Protected
3. Private

-------------------------------------------------------------------------------------------------------------------------------------------------
Visibility mode	|	With in class using member function		|	Child class using member function  | 	Outside of the function |
-------------------------------------------------------------------------------------------------------------------------------------------------
Public		|		Yes					|	        Yes    		           |	       Yes	    	|

Protected	|		Yes					|	Yes(only through Inheritance)	   |		No 		|

Private		|		Yes					|		No 			   |		No              |
-------------------------------------------------------------------------------------------------------------------------------------------------

*/
#include <iostream>
using namespace std;

class A {
protected:
	int y;
private:
	int z;
public:
	int x;
    A(){}
    A(int a,int b,int c):x(a),y(b),z(c){}

    // Data Abstraction table 1
    // Printing within class
    void print()
    {
        cout << x << "  " << y << "  " <<  z <<"\n";  // 11 22 33
    }

    void caller(){
        print();
    }

};

class B : public A {

public:
    // Data Abstraction table 2(Accessing protected member of base class in derived(this) class)
    void print(int a,int b)
    {  
        x=a;y=b;
        cout << x << "  " << y << "  " <<  "\n";        // 44  55
    }
};

// Driver code
int main()
{
   A a(11,22,33);
   a.print();

   // Data Abstraction table 2
   B b;
   b.print(44,55);
   
   // Data Abstraction table 3
   cout << a.x <<  "\n";                //  11
   //cout << a.y <<  "\n";  // We can't able to use protected member other then inside(same) class or in derived class(Inherited)
   //cout << a.z <<  "\n";  // We can't able to use private member other inside(same/base) class
   return 0;
}

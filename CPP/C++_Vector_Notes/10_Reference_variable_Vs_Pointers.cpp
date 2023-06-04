#include <iostream>
using namespace std;

/*
Pointer:-
-------
1. Pointer can be initialized at anytime.
2. Pointer can be pointed to another object at any time.
3. Seperate memory is created.
4. Pointer can point to null(NULL)( int *p=0;)

            Vs 

Reference Variable:-
-------------------
1. Reference must be initialized when it is created.
2. Once reference is initialized to an object ,it 
   can't be change to another object.
3. No seperate memory is created.
4. Reference variable always reference to object/address.   

*/
// Small example with return value concept
void foo()
{
    cout << "FOO\n";
}

int main()
{
   foo();
   //cout << "Foo" << foo(); // Error it will give error because it is expecting value here from function
   
   return 0;
}

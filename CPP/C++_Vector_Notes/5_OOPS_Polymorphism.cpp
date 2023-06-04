#include<iostream>
using namespace std;

/*
Polymorphism:-
- A single entity can exist in more than one form.
Polymorphism
-----------
|- Compile time ( early binding )
	|- Function Overloading 
	|- Operator Overloading
	
|- Runtime  ( Late binding )
	|- Virtual Function
	
static or early binding:-
- By default matching of the function call with the correct function defination happens at compile 
  time it is called early binding 
- It is achived through function overloading and operator overloading.

dynamic or late binding:-
- By default matching of the function call with the correct function defination happens at run 
  time it is called dynamic binding 
- It is achived through vitual function .
*/

#include <iostream>
using namespace std;

/*
NameMangaling:-
- Name mangling is the process used by C++ compilers , that changes name to every function by adding additional
  information based on function name and its arguments
- Function Overloading will use namemangling concept.
*/

void print(int x)
{  
    cout << "X - " << x <<  "\n";   // 44
}

void print(float f)
{  
    cout << "F - " << f <<  "\n";   // 4.4
}
/*
ERROR:-
- The return type pf function is not a factor in distinguishing overload functions.

float print(float f)
{  
    cout << "F - " << f <<  "\n";   
}
*/
int main()
{
   // print(4.4);  // Error Ambiougas {To solve this we can add print method with double as parameter}
   print(4.4f); // We need to specify f in value so it will consider as float
   print(44);

   return 0;
}
#include <iostream>
using namespace std;

/*
Class:-
1. It is special mechanisum of binding data member and data in a single unit.
2. Memory is not allocated when it is created.  // Justify
3. Defination is created once.

- It is special type of structure.
- It is user define data type or abstruct datatype.
- Memory is not allocated for member function.
        VS 

Object:-
1. Instance of class
2. Memory is allocated when it is created.  
3. It is created many time as you require.
*/
class A{
public:
    int x;
    
    // It is called member function  , It' possible in C++ only not in C.
    void foo(){}
};

struct st{};
class B{};

int main()
{
   A a;
   // size is 1 for below case to show the object existance.
   cout <<" Empty structure size => " << sizeof(st) << "\n";  // 1
   cout <<" Empty class size => " << sizeof(B) << "\n";       // 1
 
   return 0;
}

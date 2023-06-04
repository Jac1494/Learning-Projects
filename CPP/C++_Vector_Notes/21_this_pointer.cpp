#include <iostream>
using namespace std;

/*

This Pointer:-
- This pointer is collect the address of every object
- Whenever a member function is called using object , this pointer is automatically
  passed to the called member function as an implicit inbuilt argument.
- In a const member function this pointer is a pointer to const.
- static member is part of class not object, so static member 
  function does not have a this pointer.
- this pointer is not modifiable.
- Overloaded operators that are member function have an implicit this parameter bound to the first operand.
- To excess value using this pointer

obj.x = (&obj)->x = (this)->x = (*this).x 

*/

class A{
public:
    int x;
    
    void set(int a){
        x=a;
    }
    int get(){
        return x;
    }
    void isNumDivBy2()
    {
        // This pointer is hold current object address,
        if(((this->get())&1)==0)
            cout << "Number is Divided by 2\n";     // This is Execute
        else
            cout << "Number is Not Divided by 2\n";
    }

};
int main()
{
   A a;
   a.set(6);
   a.isNumDivBy2();

   return 0;
}


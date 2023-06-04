/*
Copy constructor:-
- "A copy constructor is a special case of constructor , used to make a copy of one class object and 
  initialize it by using another object of the same class type."

- Example:-  
  A obj1, obj2;
  obj2=obj1;      // Assignment  (Assignement operator)
   
  A obj2 = obj1;  // Initialization   (Copy Constructor)

- Copy constructor means both object using same memory space.

Copy constructor is invoked in 3 situations.
1.  When an object is used to initialized another object.
    A obj2(obj1);  or A obj2 = obj1;

2. When an object is passed as a parameter to a function , where a copy of the 
   arguments are created for the function to operate on.
    A obj2 = fun (obj1);

3. when a function returns an object to create a copy of the the values retured by 
   the function.
    A fun(A ob1)
    {
      A temp;
      return temp;
    } 

4. When compiler generator a temporary objects.
*/

#include<iostream>
using namespace std;

class A {
 
  public:
  A(){      
      cout << "Default constructor\n";
  }
  A(A& ob){
      cout << "Copy constructor\n";
  }
  ~A(){
      cout << "Destructor\n";
  }

};

  A fun(A ob)
  {
    return ob;
  }
  void foo(A ob)
  {
  }

int main(){
  
  A a;           // Default Constructor
  cout << "=========================================\n";
  A b = fun(a);  // 1 for fun(a) (Constructor)
                 // 2 for return assignment (Constructor)
                 // 3 for destructor fun(a)
  cout << "=========================================\n";
  foo(a);        // 1 for foo(a) (Constructor)
                 // Destructor
  cout << "=========================================\n";
                 // Destutor for a,b
  return 0;
}
/*
Output:-
Default constructor
=========================================
Copy constructor
Copy constructor
Destructor
=========================================
Copy constructor
Destructor
=========================================
Destructor
Destructor
*/

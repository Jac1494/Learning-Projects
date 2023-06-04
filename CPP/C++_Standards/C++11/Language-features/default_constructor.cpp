/*
Default functions:-
- A more elegant, efficient way to provide a default implementation of a function, such as a constructor.
*/

class A{
   public:
   A(int num) {}
   
   //C++ 11
   A()=default; // Force compiler to generate the default constructor
};

A obj;

int main(){}

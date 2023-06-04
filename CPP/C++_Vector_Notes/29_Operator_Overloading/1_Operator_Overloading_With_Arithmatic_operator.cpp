/*
Operator Overloading:-
- The facility of giving a special meaning to an operator without changing the existing
  meaning is refered to as operator overloading.
- A operator can be overloaded by creating a special function called operator function".  
- With predefined datatype we can able to perform arithmatic and other operation.
- So to give this support to user defined data type.
  
  example:-
  struct st ob1,ob2,ob3;
  ob1=ob2+ob3;

- Syntax:-
  return_type classname::operator Op(arg ...){}
  // Op -> it'is operator is goint to be overlaoded
  // operator -> it'is member function or friend function
*/

#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}

  // Arithmatic operator overloading
  A operator +(A &ob)
  {
    cout << "Addition operator : ";
    A temp;
    temp.x = x + ob.x;
    return temp;
  }

  A operator -(A &ob)
  {
    cout << "Substraction operator : ";
    A temp;
    temp.x = x - ob.x;
    return temp;
  }

  A operator /(A &ob)
  {
    cout << "Substraction operator : ";
    A temp;
    temp.x = x / ob.x;
    return temp;
  }

  A operator *(A &ob)
  {
    cout << "Substraction operator : ";
    A temp;
    temp.x = x * ob.x;
    return temp;
  }

  void print()
  {
    cout << "X - " << x << "\n";
  }

};

int main(){

  A a(10),b(20),c,d(5);
  a.print();
  c = a + b;  // It will transform to => a.operator + (obj2);  // 30
  c.print();
  c = c - a;  // It will transform to => a.operator - (obj2);  // 20
  c.print();
  c = c / d;  // It will transform to => a.operator / (obj2);  // 4
  c.print();
  c = c * d;  // It will transform to => a.operator * (obj2);  // 20
  c.print();

  return 0;
}
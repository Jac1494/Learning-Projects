#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}

  // Arithmatic operator overloading
  A operator +(int var)
  {
    cout << "a + 100 => a.operator + (100) ";
    A temp;
    temp.x = x + var;
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
  c = a + 100;  
  // It will transform to => a.operator + (100);  // member function
  //                         a.operator + (obj , 100);  // friend function

  // 100 + obj => operator + (100 , obj); // TO DO
  c.print();    // 110
  return 0;
}
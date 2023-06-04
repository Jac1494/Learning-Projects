/*
Const member function and Const object:-
- For both We can't able to assign value to non static variable. But it 
  is work for static variable.



*/

#include<iostream>
using namespace std;

class A {

  public:
  int x=11;
  static int y;

  void setdata() const
  {
    //x = 55; ERROR -> we can't assign value to non static variable
    y=77;
  }

  void print() const{
     y=88;
     // x=22; ERROR -> we can't assign value to non static variable
     cout << x << "  " << y << "\n";  // 11  88
  }
  
};
int A::y=99;

int main(){
  A a;
  a.print();

  // Const object 
  const A cobj;
  cobj.setdata();
  cobj.print();         // 11  88
  return 0;
}
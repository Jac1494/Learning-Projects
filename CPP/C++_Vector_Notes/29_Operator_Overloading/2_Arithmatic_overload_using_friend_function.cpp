#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}

  void print()
  {
    cout << "X - " << x << "\n";
  }
  friend A operator +(A &,A &);
};

  // Arithmatic operator overloading using friend function
  A operator +(A &ob1,A &ob2)
  {
    cout << "Addition operator : ";
    static A temp;
    temp.x = ob1.x + ob2.x;
    return temp;
  }

int main(){

  A a(10),b(20),c;
  a.print();
  c = a + b ;  // => c = operator + (a,b);
  c.print();

  return 0;
}
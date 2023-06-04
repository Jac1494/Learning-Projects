#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}
  
  /* Assignment operator overloading
  - If we don't call assignment operator explicity then also, 
    Default assignment operator will operform this.
  - So If we try to overload this using friend function then
    compiler give ambiguity error , So it is not possible using friend function.
  */  

  A operator =(A &ob)
  {
    cout << "Assignment operator : ";
    x = ob.x;
    return *this;
  }

  void print()
  {
    cout << "X - " << x << "\n";
  }

};

int main(){

  A a(10),b;
  a.print();
  b = a;  // It will transform to => 
  b.print();

  return 0;
}

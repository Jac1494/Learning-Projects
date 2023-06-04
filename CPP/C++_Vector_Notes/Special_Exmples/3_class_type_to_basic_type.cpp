#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}

  operator int(){
     int t;
     t=x;
     return t;
  }
};

int main(){

  // class to basic type conversion

  A a(11);
  int x;
  x=a;   // Now both are treat as integer
  cout << "X - " << x << "\n";
  return 0;
}
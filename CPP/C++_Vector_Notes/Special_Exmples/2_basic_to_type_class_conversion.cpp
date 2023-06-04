#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}

  void print(){
    cout << "X - " << x << "\n";
  }
};

int main(){

  A a;
  int x=11;
  a=x;   // Transform to => a(x)
  a.print();
  return 0;
}
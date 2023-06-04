#include<iostream>
using namespace std;

class A {

  public:
  int x;
  int a[5];

  A(){
    cout << "Assign Value to Array in Constructor \n";
    for(int i=0;i<5;i++)
    a[i]=i+1;
  }
  
  // [] subscript operator overloading  
  int operator [](int index)
  {
    return a[index];
  }

  // () operator overloading  
  void operator ()(int var)
  {
    x = var;
  }

  void print()
  {
    cout << "X - " << x << "\n";
  }

};

int main(){

  A a;

  // [] subscript operator overloading  

  for(int i=0;i<5;i++)
  cout << a[i] << " ";
  cout << "\n";
 
  // () operator overloading  
  a(11);
  a.print();
  return 0;
}
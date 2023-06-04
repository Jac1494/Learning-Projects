#include<iostream>
using namespace std;

class A {

  public:
  int x;
  A(){}
  A(int a):x(a){}
  int getValue() const { return x;}

  // Unary operator overloading
  A& operator ++()
  {
    cout << "(++)PreIncrement operator : ";
    x += 1;
    return *this;
  }

  A& operator --()
  {
    cout << "(--)Predecrement operator : ";
    x -= 1;
    return *this;
  }

  A operator ++(int)   // pass (int) to only for differenciate
  {
    cout << "PostIncrement(++) operator : ";
    A temp = *this;
    x += 1;
    return temp;
  }

  A operator --(int)   // pass (int) to only for differenciate
  {
    cout << "Postdecrement(--) operator : ";
    A temp = *this;
    x -= 1;
    return temp;
  }

};

// If we take print function in class. then for post 
// increment we will get incremented value.

ostream & operator << (ostream & o, const A & n)
{
    return o << (n.getValue());
}

int main(){

  A a(11);
  cout << a << "\n";  
  cout << a++ << "\n";  
  cout << a << "\n";
  cout << ++a << "\n";  
  cout << a << "\n";
  cout << --a << "\n"; 
  cout << a << "\n"; 
  cout << a-- << "\n";
  cout << a << "\n"; 
  return 0;
}
/*
11
PostIncrement(++) operator : 11
12
(++)PreIncrement operator : 13
13
(--)Predecrement operator : 12
12
Postdecrement(--) operator : 12
11
*/

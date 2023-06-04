/*
Dynamic constructor:-
- If the constructor are invoked to the dynamically created objects 
  those constructors are called as dynamic constructors.
- Memory allocated using "new operator".  
*/

#include<iostream>
#include<cstring>
using namespace std;

class A {
 
  int x,y;
  public:
  A():x(11),y(22){}
  A(int a,int b):x(a),y(b){}

  void print(void)
  {
    cout << "X - " << x << " | Y - " << y << "\n";
  }
};

int main(){
  
  A *obj1 = new A;
  obj1->print();            // 11 22
  delete obj1;

  A *obj2 = new A(33,44);
  obj2->print();            // 33 44 
  delete obj2;

  return 0;
}

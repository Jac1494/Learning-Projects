#include<iostream>
using namespace std;

/*
Why << and >> operator can't be overloaded with member function ..?
- Suppose, the syntax is 
        cout >> obj; => Tranform to cout.operator << (obj);
- It would required our overloaded function to be part of ostream class not
  our class. And we can't allow to modify the ostream class.
      
*/

class A {

  public:
  int x;
  friend istream& operator >>(istream &in, A &obj);
  friend ostream& operator <<(ostream &out, A &obj);
};

  // >> operator overloading  
  istream& operator >>(istream &in, A &obj)
  {
    in >> obj.x;
    return in;
  }

  // << operator overloading  
  ostream& operator <<(ostream &out, A &obj)
  {
    out << "X - " << obj.x << "\n";
    return out;
  }

int main(){

  A a;
  cin >> a;
  cout << a;
  return 0;
}

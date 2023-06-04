/*
Deep constructor:-
- "Deep copy is type of copy in which data members of one object is copy 
  into the other object using explicit copy constructor."
- Use of user defined copy constructor is when object has pointer or any 
  runtime allocation of resource like file handle , network connection.
*/

#include<iostream>
#include<cstring>
using namespace std;

class A {
 
  char *str;

  public:
  A (const char *p)
  {
    str = new char[strlen(p)+1];
    strcpy(str,p);
  }
  // explicit copy constructor
  A (A &ob)  
  {
    str = new char[strlen(ob.str)+1];
    strcpy(str,ob.str);
  }
  void modify(void)
  {
    str[0]='J';
  }
  void print(void)
  {
    cout << "Str - " << str << "\n";
  }
};

int main(){
  
  A obj1("Hello");
  A obj2 = obj1;
  obj1.print();        // Hello
  obj2.print();        // Hello
  cout << "===========\n";
  obj1.modify();       
  obj1.print();        // Jello
  obj2.print();        // Hello
  return 0;
}

/*
Shallow constructor:-
- "Shallow copy is type of copy in which data members of one object is copy 
  into the other object using default copy constructor."
- Shallow copy is not suitable for copy objects containig dynamically allocated
  pointers."
- Both object are point to same location.  
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
  obj2.print();        // Jello
  return 0;
}

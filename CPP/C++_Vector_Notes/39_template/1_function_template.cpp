#include<iostream>
using namespace std;

/*
Tempalates:-
- Templates are feature of the programing language that allows functions and classes
  to operate with generic types.
*/
// Function templates
template < class T >
void swapping( T &var1, T &var2)
{
    T tmp;
    tmp=var1;
    var1=var2;
    var2=tmp;
}

int main(){

  int a = 11 , b = 22;
  float c = 3.3 , d = 4.4;
  char e = 'a' , f = 'b';

  cout << " Int a - " << a << " | b - " << b << "\n";
  cout << " float c - " << c << " | d - " << d << "\n";
  cout << " float e - " << e << " | f - " << f << "\n";
  cout << "========================="<< "\n";
  swapping(a,b);
  swapping(c,d);
  swapping(e,f);
  cout << " Int a - " << a << " | b - " << b << "\n";
  cout << " float c - " << c << " | d - " << d << "\n";
  cout << " float e - " << e << " | f - " << f << "\n";

  return 0;
}

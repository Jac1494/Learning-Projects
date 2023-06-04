#include <iostream>
using namespace std;

/*
Reference Variable:-
- It is aliaz name for already available variable.
- No seperate memory is allocated like pointer
- syntax:-
  datatype &aliaz_name = variable;   // Only assigning variable to reference variable works, not constant
  int x = 10;
  int &r = x;  // Correct
  int &r = 10;  // Error
*/

// Complex for compiler
int sum(int &r1, int &r2)
{
    r1=1,r2=2;
    return r1+r2;
}

// Simple for compiler
int sum1(int r1, int r2)
{
    return r1+r2;
}

int main()
{
   int x = 11;
   cout << " X => " << x << "\n";           // 11
   cout << " Sum => " << sum(x,x) << "\n";  // 4
   cout << " X => " << x << "\n";           // 2

   // How to use referance variable for pointer
   int *p = &x;
   int *(&rp)=p;
   *rp=44;
   cout << " X => " << x << "\n";           // 44

   // How to use referance variable for array
   int a[1] = {x};

   int (&ra)[1]=a;
   cout << " ra[0] => " << ra[0] << "\n";   //  44
   ra[0]=55;
   cout << " ra[0] => " << ra[0] << "\n";   //  55

   // How to use referance variable for single array element
   int&r=a[0];
   r=66;
   cout << " ra[0] => " << ra[0] << "\n";   //  66

   // int &rtest= 1; // Must be initilize with identifiers, it's need address

   return 0;
}

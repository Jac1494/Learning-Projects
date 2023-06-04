/*
Binary Literals:-
- Now we can directly write Binary literals.
- Gcc Compiler had this feature but not standardized , now C++ 14 standarized it.
- Binary literals provide a convenient way to represent a base-2 number. 
  It is possible to separate digits with '
*/

#include<iostream>
using namespace std;

int main(){

   int b1 = 0xFF;         // Binary 11111111
   cout << b1 << endl;    // 255
 
   int b2 = 0b11111111;   // 0b OR 0B
   cout << b2 << endl;    // 255
   
   b2 = 0b0001'0001;   // seperated digit
   cout << b2 << endl;    // 17
   return 0;
}
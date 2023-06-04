/*
String datatype:-
- In normally we used to take char pointer or array for string,
  In that assigning new string or string concate are complecate operation 
  for programer(Reallocate memory and etc.) So this is better
  Solution for that. It is only allocate 32 byte for all case.
*/
#include <iostream>
using namespace std;

// Bool and string datatype
bool iseven(int x)
{
    if(x&1) return 0;
    else    return 1;
}

int main()
{
   int x = 3;
   if(iseven(x))
        cout << "Number is even\n";
   else
        cout << "Number is odd\n";  // Number is odd

   string S="Hello World";     
   cout << S << "\n";               // Hello World
   cout << sizeof(S) << "\n";	    // 32 

   S="String is updated";
   cout << S << "\n";               // String is updated
   cout << sizeof(S) << "\n";       // 32 

   string S1="1. ",S3;
   S3=S1+S;     
   cout << S3 << "\n";		    // 1. Hello World

   return 0;
}


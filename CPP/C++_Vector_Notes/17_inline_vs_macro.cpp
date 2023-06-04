#include<iostream>
using namespace std;

/*
Inline function:-
- For inline function compiler replace function call with function defination. 
- It is effecient when function call/return time is more the function execution time. OR
  functions are small. (get() or set() functions)
- Even inline is added to function , compiler only decide is function call should replace 
  with function defination or not.
- It is used to avoid function call overheads. But it will increase code size. 


Difference Macro and Inline:-
---------------------------
- For macro single instruction/pattern is expand at place of call, But for inline full
  function body is placed.
- Macro resolved at preprossor time , Inline resolved at compile time.  
- Macro is replaced for sure, But inline will execute or not that will decide by compiler even 
  user nametion inline in function defination.
*/

inline int sum(int x,int y)
{
    return x+y;
}

int main()
{
   int r = sum(11,22);
   cout << r << "\n";       // 33
   return 0;
}

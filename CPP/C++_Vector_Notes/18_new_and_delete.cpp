#include<iostream>
using namespace std;

/*
DMA(Dynamic Memory Allocation):-
- In C++ new is available for dynamic memory allocation.
- syntax:-
  datatype *ptr_name = newdatatype;
- Upon failure it will return bad_alloc
----------------------------------------------------------
Malloc:-
1. It is Function 
2. can't be initialize
3. Need to provide typecasting
4. Return (void *) upon succeful execution
5. Can resize using realloc 
6. Upon failure return NULL pointer
7. We can free memory using "free"
8. malloc and free can't call consturctor and destructor, SO we can't
   initialize or deinitilaze data with that.

New:-
1. It is Operator
2. Initialization is possible
3. Typecasting is not required
4. Return exact data type 
5. Can't resize like realloc 
6. Upon failure return bad_alloc
7. We can free memory using "delete"
8. new and delet can call consturctor and destructor, So it will
   initialize & deinitilaze data automatically.
*/

int main()
{
   int *p1 = new int;
   *p1=11;
   cout << *p1 << "\n";       // 11

   int *p2 = new int(22);    // We can also able to directly assign value 
   cout << *p2 << "\n";       // 22


   return 0;
}
#include <iostream>
using namespace std;

/*
Note:-
- By default compiler allocate 16 bytes of memory for each function
- If number of variable is inside function reach more then 16 byte then funcion will allocate 32 bytes memory
- In this memory allocation return 0 is also counted
- This memory allocated in multiplication of 16 bytes only like 16,32,48...
*/

// Scope Resolution
int x = 11;             // Compiler create label for this variable

int main()
{
   int x = 22;
   cout << "Global X => " << ::x << "\n";
   cout << "Local X => " << x << "\n";
   return 0;
}

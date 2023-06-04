#include <iostream>
using namespace std;

int main()
{
   // Types of Variable Initialization
   // 1. Copy Initialization
   int num1=1.1;

   // 2. Direct Initialization
   int num2(1.1);           // Warning => It will convert double into int

   // 3. Brase Initialization
   //int num3{1.1};           // Error: double can't convert to int
   
   cout << " Num1 => " << num1;         // 1
   cout << " Num2 => " << num2 << "\n"; // 1
   
   return 0;
}

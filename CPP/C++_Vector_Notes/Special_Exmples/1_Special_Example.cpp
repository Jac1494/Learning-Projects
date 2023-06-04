#include <iostream>
using namespace std;

struct Empty1 {
    int :8 ;   // int with 8 bit => (1 byte)
}; 

struct Empty2 {
    int :9 ;   // int with 9 bit => (2 byte)
}; 

int main()
{
   cout << sizeof(Empty1) << "\n";  // 1
   cout << sizeof(Empty2) << "\n";  // 2
   return 0;
}
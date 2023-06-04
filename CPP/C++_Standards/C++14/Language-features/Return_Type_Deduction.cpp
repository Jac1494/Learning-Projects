// Return Type Deduction
/*
 * 1. Using an auto return type in C++14, the compiler will attempt to deduce the type for you
 *    1) auto 
 *    2) decltype(auto) 
 */

#include<iostream>
using namespace std;

// Example: 1
auto add(int a,int b) { return a+b; }     // return int

// Example: 2
auto increment(int& a) { a++; return a; } // return int&

int main(){
   int p = 10;
   int& y = increment(p);  // Error
/* Solution is 
   1 . auto& increment(int& a) { a++; return a; }
   2 . decltype(auto) increment(int& a) { a++; return a; } // return int&
*/
   cout << p << endl;
   cout << y << endl;
   
// const int x = 0;
// auto x1 = x; // int 
// decltype(auto) x2 = x; // const int 

// int y = 0;
// int& y1 = y;
// auto y2 = y1;  // int
// decltype(auto) y3 = y1; //int&

// int&& z = 0;
// auto z1= std::move(z);  //int 
// decltype(auto) z2 = std::move(z); // int&&   
   
   return 0;
}





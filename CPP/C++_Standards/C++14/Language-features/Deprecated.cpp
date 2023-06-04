// [[Deprecated]]
/*
 * 1. Deprecated means use of the name or entity declared with this attribute us allowed, 
 *    but discouraged for some reason
 * 2. Compiler gives warnings and if string literals are provied they are included in warnings.
 */

// LIST WHAT CAN BE DEPRECATED:
/*
 * class, struct ,union
 * typedef
 * variable 
 * non-static data member
 * function
 * namespace
 * enumeration 
 * enumerator
 * template specialization
 */

#include<iostream>
using namespace std;

[[deprecated("This function will be replaced with template add function")]]
int add(int a,int b) { return a+b;}

int main(){
   cout << add(1,2);
   return 0;
}
/*
<source>:28:12: warning: 'add' is deprecated: This function will be replaced with template add function [-Wdeprecated-declarations]
   cout << add(1,2);
*/   

// Variable Template
/*
 * 1. Before C++14 we had function template and class template , now we have variable template
 */
#include<iostream>
#include<complex>
using namespace std;

template<typename T>
T pi = T(3.1415926535897932384626433L);

int main(){
   pi<char> = 'a';
   cout.precision(std::numeric_limits<long double>::max_digits10);  // Need C++17
   std::cout << pi<int> << endl;
   std::cout << pi<float> << endl;
   std::cout << pi<double> << endl;
   std::cout << pi<long double> << endl;
   std::cout << pi<char> << endl;
   return 0;
}
/*
3
3.14159274101257324219
3.141592653589793116
3.14159265358979323851
a
*/

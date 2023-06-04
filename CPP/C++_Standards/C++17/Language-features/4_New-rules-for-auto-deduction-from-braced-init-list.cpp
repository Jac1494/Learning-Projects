/*
New rules for auto deduction from braced-init-list:-
- Changes to auto deduction when used with the uniform initialization syntax. 
- Previously, auto x {3}; deduces a std::initializer_list<int>, 
  which now deduces to int.
NOTE:- 
- Looks like this feature is implemented from starting.
*/

#include <iostream>
using namespace std;

int main()
{
	// auto x1 {1, 2, 3}; // error: not a single element 
	// It will work only for initializer_list
	auto x2 = {1, 2, 3}; // x2 is std::initializer_list<int>
	auto x3 {3}; // x3 is int
	auto x4 {3.0}; // x4 is double

	return 0;
}

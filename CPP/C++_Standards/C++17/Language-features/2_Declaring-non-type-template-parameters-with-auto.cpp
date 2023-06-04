/*
Declaring non-type template parameters with auto:-
- Following the deduction rules of auto, while respecting the non-type 
  template parameter list of allowable types[*], template arguments can 
  be deduced from the types of its arguments:
*/

#include <iostream>
using namespace std;

template <auto... seq>
struct my_integer_sequence {};

int main()
{
	// Explicitly pass type `int` as template argument.
	auto seq = std::integer_sequence<int, 0, 1, 2>();
	// Type is deduced to be `int`.
	auto seq2 = my_integer_sequence<0, 1, 2>();

	auto seq3 = my_integer_sequence<0.1, 1.1, 2.1>(); 
	// C++20(gcc compiler) support this but C++17 give error
	// It give error "non-type template argument of type 'double' is not yet supported"
	return 0;
}

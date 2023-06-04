/*
std::forward:-
- Returns the arguments passed to it while maintaining their value category and 
  cv-qualifiers. Useful for generic code and factories. Used in conjunction with 
  forwarding references.
*/

#include <iostream>
using namespace std; 

struct A {
	A() = default;
	A(const A& o) { std::cout << "copied" << std::endl; }
	A(A&& o) { std::cout << "moved" << std::endl; }
};

template <typename T>
A wrapper(T&& arg) {
	return A{std::forward<T>(arg)};
}

// With below code we will get all copied 
// template <typename T>
// A wrapper(T&& arg) {
//   return A{arg};
// }

int main()
{
	wrapper(A{}); // moved
	A a;
	wrapper(a); // copied
	wrapper(std::move(a)); // moved
	return 0;
}

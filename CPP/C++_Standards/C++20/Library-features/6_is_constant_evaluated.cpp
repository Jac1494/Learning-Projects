/*
std::is_constant_evaluated:-
- Predicate function which is truthy when it is called in a compile-time context.
*/

#include <iostream>
using namespace std;

constexpr bool is_compile_time() {
	return std::is_constant_evaluated();
}

int main()
{

	constexpr bool a = is_compile_time(); // true
	bool b = is_compile_time(); // false

	cout << "a - " << a << " b - " << b << "\n";
	return 0;
}

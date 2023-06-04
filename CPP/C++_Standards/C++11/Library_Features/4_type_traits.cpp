/*
Type traits:-
- It defines a compile-time template-based interface to query or modify the properties of types.
- All function list is available at https://en.cppreference.com/w/cpp/header/type_traits and https://cplusplus.com/reference/type_traits/.
*/

// is_integral example
#include <iostream>
#include <type_traits>

int main() {
	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << std::is_integral<char>::value << std::endl;      // char: true
	std::cout << "int: " << std::is_integral<int>::value << std::endl;        // int:  true
	std::cout << "float: " << std::is_integral<float>::value << std::endl;    // float: false 

	return 0;
}

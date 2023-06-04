/*
Synchronized buffered outputstream:-
- Buffers output operations for the wrapped output stream ensuring synchronization 
  (i.e. no interleaving of output).

https://en.cppreference.com/w/cpp/io/basic_osyncstream  
*/

#include <iostream>
#include <syncstream>

int main() {
	int x = 11;
	std::osyncstream{std::cout} << "The value of x is:" << x << std::endl;  // 11

	return 0;
}

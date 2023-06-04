/*
Bit operations:-
- C++20 provides a new <bit> header which provides some bit operations including popcount.
- https://en.cppreference.com/w/cpp/header/bit // More functions
*/

#include <iostream>
#include <bit>
using namespace std;

int main() {

	cout << std::popcount(0u) << "\n"; // 0
	cout << std::popcount(1u) << "\n";; // 1
	cout << std::popcount(0b1111'0000u) << "\n";; // 4

	return 0;
}

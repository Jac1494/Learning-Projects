/*
std::bit_cast:-
- A safer way to reinterpret an object from one type to another.
*/

#include <iostream>
#include <bit>

int main()
{
	float f = 123.0;
	int i = std::bit_cast<int>(f);
	std::cout << f << " " << i << "\n";  // 123 1123418112

	return 0;
}

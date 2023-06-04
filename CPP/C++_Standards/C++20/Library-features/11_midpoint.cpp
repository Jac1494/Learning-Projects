/*
std::midpoint
Calculate the midpoint of two integers safely (without overflow).
*/

#include <iostream>
#include <numeric>

int main()
{
	std::cout << std::midpoint(1, 3) << "\n";  // 2

	return 0;
}

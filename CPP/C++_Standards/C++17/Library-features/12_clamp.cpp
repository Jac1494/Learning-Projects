/*
std::clamp
Clamp given value between a lower and upper bound.
*/

#include <iostream>
#include <algorithm>
using namespace std; 
int main()
{
	cout << std::clamp(42, -1, 1) << "\n"; //  1
	cout << std::clamp(-42, -1, 1) << "\n"; //  -1
	cout << std::clamp(0, -1, 1) << "\n"; //  0

	// `std::clamp` also accepts a custom comparator:
	cout << std::clamp(0, -1, 1, std::less<>{}) << "\n"; //  0
	return 0;
}

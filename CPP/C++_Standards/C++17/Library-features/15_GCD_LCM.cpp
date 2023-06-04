/*
GCD and LCM:-
-Greatest common divisor (GCD) and least common multiple (LCM).
*/

#include <iostream>
#include <numeric>
using namespace std; 

int main()
{
	const int p = 9;
	const int q = 3;
	cout << std::gcd(p, q) << "\n"; //  3
	cout << std::lcm(p, q) << "\n"; //  9

	return 0;
}

/*
constexpr lambda
- Compile-time lambdas using constexpr.

Note:- 
- Check assembly difference for addOne compile time it is marked as lambda.
*/

#include <iostream>
using namespace std;

constexpr int addOne(int n) {
	return [n] { return n + 1; }();
}

int addOne1(int n) {
	return [n] { return n + 1; }();
}

int main()
{

	cout << addOne(1) << "\n";      // 2
	cout << addOne1(1) << "\n";     // 2

	return 0;
}

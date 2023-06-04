/*
constexpr if:-
- Write code that is instantiated depending on a compile-time condition.
*/

#include <iostream>
using namespace std;

template <typename T>
constexpr bool isIntegral() {
	if constexpr (std::is_integral<T>::value) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	static_assert(isIntegral<int>() == true);
	static_assert(isIntegral<char>() == true);
	static_assert(isIntegral<double>() == false);
	struct S {};
	static_assert(isIntegral<S>() == false);    

	return 0;
}

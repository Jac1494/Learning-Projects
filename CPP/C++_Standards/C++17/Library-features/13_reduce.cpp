/*
std::reduce:-
- Fold over a given range of elements. Conceptually similar to std::accumulate, 
  but std::reduce will perform the fold in parallel. Due to the fold being done 
  in parallel, if you specify a binary operation, it is required to be associative 
  and commutative. 
- A given binary operation also should not change any element or invalidate any 
  iterators within the given range.

- The default binary operation is std::plus with an initial value of 0.
https://en.cppreference.com/w/cpp/algorithm/accumulate
*/

#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include <array>
using namespace std; 

int main()
{
	const std::array<int, 4> a{ 1, 2, 3 ,4 };
	cout << std::reduce(std::cbegin(a), std::cend(a)) << "\n"; //  10
								   // Using a custom binary op:
	cout << std::reduce(std::cbegin(a), std::cend(a), 1, std::multiplies<>{}) << "\n"; //  24

	const std::array<int, 2> b{ 1, 2 };
	const auto product_times_ten = [](const auto a, const auto b) { return a * b * 10; };

	cout << std::transform_reduce(std::cbegin(a), std::cend(a), std::cbegin(b), 0, std::plus<>{}, product_times_ten) << "\n"; // 50

	const auto times_ten = [](const auto n) { return n * 10; };
	cout << std::transform_reduce(std::cbegin(a), std::cend(a), 1, std::plus<>{}, times_ten) << "\n"; // 101

	return 0;
}

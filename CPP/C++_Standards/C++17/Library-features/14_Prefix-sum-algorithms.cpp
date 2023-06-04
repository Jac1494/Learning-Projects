/*
Prefix sum algorithms:-
- Support for prefix sums (both inclusive and exclusive scans) along with transformations.
*/

#include <iostream>
#include <iterator>
#include <numeric>
#include <array>
using namespace std; 

int main()
{
	const std::array<int, 3> a{ 1, 2, 3 };

	std::inclusive_scan(std::cbegin(a), std::cend(a),
			std::ostream_iterator<int>{ std::cout, " " }, std::plus<>{}); // 1 3 6
	cout << "\n";

	std::exclusive_scan(std::cbegin(a), std::cend(a),
			std::ostream_iterator<int>{ std::cout, " " }, 0, std::plus<>{}); // 0 1 3
	cout << "\n";

	const auto times_ten = [](const auto n) { return n * 10; };

	std::transform_inclusive_scan(std::cbegin(a), std::cend(a),
			std::ostream_iterator<int>{ std::cout, " " }, std::plus<>{}, times_ten); // 10 30 60
	cout << "\n";

	std::transform_exclusive_scan(std::cbegin(a), std::cend(a),
			std::ostream_iterator<int>{ std::cout, " " }, 0, std::plus<>{}, times_ten); // 0 10 30
	cout << "\n";
	return 0;
}

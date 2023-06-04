/*
Structured bindings:-
- A proposal for de-structuring initialization, that would allow writing 
  auto [ x, y, z ] = expr; where the type of expr was a tuple-like object, 
  whose elements would be bound to the variables x, y, and z (which this construct declares). 
  
- Tuple-like objects include std::tuple, std::pair, std::array, and aggregate structures.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

using Coordinate = std::pair<int, int>;
Coordinate origin() {
	return Coordinate{11, 22};
}

int main()
{
	const auto [ x, y ] = origin();
	cout << x << "\n"; // == 11
	cout << y << "\n"; // == 22

	std::unordered_map<std::string, int> mapping {
		{"a", 1},
			{"b", 2},
			{"c", 3}
	};

	// Destructure by reference.  
	for (const auto& [key, value] : mapping) {
		cout << key << " => " << value << "\n";     // Output order is different     
	}

	int arr[3][2] {     // both syntax will work int arr[3][2] = {
		{1, 11},
			{2, 22},
			{3, 33},
	};

	// Destructure by reference.
	for (const auto& [key, value] : arr) {
		cout << key << " => " << value << "\n";
	}

	return 0;
}
/*
11
22
c => 3
b => 2
a => 1
1 => 11
2 => 22
3 => 33
*/

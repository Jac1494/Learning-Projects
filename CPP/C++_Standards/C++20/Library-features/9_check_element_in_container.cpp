/*
Check if associative container has element:-
- Associative containers such as sets and maps have a contains member function, 
  which can be used instead of the "find and check end of iterator" idiom.
*/

#include <iostream>
#include <map>
#include <set>

int main()
{
	std::map<int, char> map {{1, 'a'}, {2, 'b'}};
	std::cout << map.contains(2) << "\n"; // true
	std::cout << map.contains(123) << "\n"; // false

	std::set<int> set {1, 2, 3};
	std::cout << set.contains(3) << "\n"; // true

	return 0;
}

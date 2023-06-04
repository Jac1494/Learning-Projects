/*
std::begin/end:-
- std::begin and std::end free functions were added to return begin and end iterators 
  of a container generically. These functions also work with raw arrays which do not 
  have begin and end member functions.
*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int CountTwos(const T& container) {
	return std::count_if(std::begin(container), std::end(container), [](int item) {
			return item == 2;
			});
}

int main()
{
	std::vector<int> vec = {2, 2, 43, 435, 4543, 534};
	int arr[8] = {2, 43, 45, 435, 32, 32, 32, 32};
	std::cout << CountTwos(vec) << "\n";  // 2
	std::cout << CountTwos(arr) << "\n";  // 1
	return 0;
}

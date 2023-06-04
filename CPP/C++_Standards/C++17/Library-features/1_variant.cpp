/*
std::variant:-
- The class template std::variant represents a type-safe union. 
- An instance of std::variant at any given time holds a value of 
  one of its alternative types (it's also possible for it to be valueless).
*/

#include <iostream>
#include <variant>
using namespace std;

int main()
{
	// syntax - 1
	std::variant<int, double> v{ 1.2 };
	cout << std::get<double>(v) << "\n"; // == 1.2
	cout << std::get<1>(v) << "\n"; // == 1.2

	v = 12;

	cout << std::get<int>(v) << "\n"; // == 12
	cout << std::get<0>(v) << "\n"; // == 12

	//std::variant<int, double> v1,v2={33,3.3}; // Error
	// syntax - 2
	std::variant<int, double> v1,v2;
	v1=33;       // If we assign double/float then it will give
		     // error in below print statement
		     // so it is safe compare to union
	v2=3.3;
	cout << std::get<int>(v1) << "\n"; // == 33
	cout << std::get<0>(v1) << "\n"; // == 33

	cout << std::get<double>(v2) << "\n"; // == 3.3
	cout << std::get<1>(v2) << "\n"; // == 3.3

	return 0;
}

/*
std::optional:-
- The class template std::optional manages an optional contained value, 
  i.e. a value that may or may not be present. A common use case for optional 
  is the return value of a function that may fail.
*/

#include <iostream>
#include <optional>
using namespace std;

std::optional<std::string> create(bool b) {
	if (b) {
		return "Godzilla";
	} else {
		return {};
	}
}

std::optional<int> create2(bool b) {
	if (b) {
		return 88;
	} else {
		return {};
	}
}

int main()
{
	cout << create(false).value_or("Empty") << "\n"; //  "Empty"
	cout << create(true).value() << "\n"; //  "Godzilla"
	cout << create(true).value_or("Hello") << "\n"; //  "Godzilla"

	// optional-returning factory functions are usable as conditions of while and if
	if (auto str = create(true)) {
		// ...
	}

	cout << create2(false).value_or(99) << "\n"; //  99
	cout << create2(true).value() << "\n"; //  88
	cout << create2(true).value_or(99) << "\n"; //  88

	return 0;
}

/*
starts_with and ends_with on strings:-
- Strings (and string views) now have the starts_with and ends_with member functions 
  to check if a string starts or ends with the given string.
*/

#include <iostream>

int main()
{
	std::string str = "foobar";
	std::cout << str.starts_with("foo") << "\n"; // true
	std::cout << str.ends_with("baz") << "\n"; // false

	return 0;
}

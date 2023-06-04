/*
std::string_view:-
- A non-owning reference to a string. Useful for providing an abstraction 
  on top of strings (e.g. for parsing).
*/

#include <iostream>
using namespace std;

int main()
{
	// Regular strings.
	std::string_view cppstr {"foo"};
	// Wide strings.
	std::wstring_view wcstr_v {L"baz"};
	// Character arrays.
	char array[3] = {'b', 'a', 'r'};
	std::string_view array_v(array, std::size(array));

	std::string str {"   trim me"};
	std::string_view v {str};
	v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));

	cout << cppstr << "\n"; //  "foo"
	cout << array_v << "\n"; //  "bar"
	cout << str << "\n"; //  "   trim me"
	cout << v<< "\n"; //  "trim me"    
	return 0;
}

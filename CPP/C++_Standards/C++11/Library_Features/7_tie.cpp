/*
std::tie:-
- Creates a tuple of lvalue references. 
- Useful for unpacking std::pair and std::tuple objects. 
- Use std::ignore as a placeholder for ignored values. In C++17, 
  structured bindings should be used instead.
*/

// tuple example
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

int main ()
{
	// With tuples...
	std::string playerName;
	std::tie(std::ignore, playerName, std::ignore) = std::make_tuple(91, "John Tavares", "NYI");

	// With pairs...
	std::string yes, no;
	std::tie(yes, no) = std::make_pair("yes", "no");

	return 0;
}

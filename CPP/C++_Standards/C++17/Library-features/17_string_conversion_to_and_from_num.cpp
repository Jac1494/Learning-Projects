/*
String conversion to/from numbers:-
- Convert integrals and floats to a string or vice-versa. Conversions are 
  non-throwing, do not allocate, and are more secure than the equivalents 
  from the C standard library.

- Users are responsible for allocating enough storage required for std::to_chars, 
  or the function will fail by setting the error code object in its return value.

- These functions allow you to optionally pass a base (defaults to base-10) or 
  a format specifier for floating type input.

    1) std::to_chars returns a (non-const) char pointer which is one-past-the-end 
       of the string that the function wrote to inside the given buffer, and an error 
       code object.
    2) std::from_chars returns a const char pointer which on success is equal to 
       the end pointer passed to the function, and an error code object.

- Both error code objects returned from these functions are equal to the default-initialized error code object on success.
*/

#include <iostream>
#include <charconv>  // Headerfile
using namespace std; 

int main()
{
	const int n1 = 123;

	cout << "String to number:-\n";
	// Can use any container, string, array, etc.
	std::string str1;
	str1.resize(3); // hold enough storage for each digit of `n1`

	const auto [ ptr, ec ] = std::to_chars(str1.data(), str1.data() + str1.size(), n1);

	if (ec == std::errc{}) { std::cout << str1 << std::endl; } // 123
	else { /* handle failure */ }

	cout << "Number to string:-\n";
	const std::string str2{ "123" };
	int n2;

	const auto [ ptr2, ec2 ] = std::from_chars(str2.data(), str2.data() + str2.size(), n2);

	if (ec2 == std::errc{}) { std::cout << n2 << std::endl; } // 123
	else { /* handle failure */ }

	return 0;
}

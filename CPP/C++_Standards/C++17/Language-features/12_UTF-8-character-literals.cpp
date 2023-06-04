/*
UTF-8 character literals:-
- A character literal that begins with u8 is a character literal of type char. 
  The value of a UTF-8 character literal is equal to its ISO 10646 code point value.
*/

#include <iostream>
using namespace std;

int main()
{
	char Value = u8'x';    
	cout << "Value - " << Value << "\n";    // x  // SUpport in C++17
	return 0;
}

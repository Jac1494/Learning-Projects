/*
Direct list initialization of enums:-
- Enums can now be initialized using braced syntax.
*/

#include <iostream>
using namespace std;

int main()
{
	enum byte : unsigned char {};
	byte a {97}; // OK
	byte b {'A'}; // OK
		      // byte c {-1}; // ERROR
	byte d = byte{49}; // OK
			   // byte e = byte{256}; // ERROR    

	cout << a << " || " << b << " || " << d << "\n" ;   // a || A || 1
	return 0;
}

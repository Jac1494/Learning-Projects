/*
Type Casting operators:-
- A Cast operator is an unary operator which forces one data type to be converted into another data type.

C++ supports four types of casting:

1. Static Cast
2. Dynamic Cast
3. Const Cast
4. Reinterpret Cast

Static Cast:-
- This is the simplest type of cast which can be used. It is a compile time cast.
  It does things like implicit conversions between types (such as int to float, or 
  pointer to void*), and it can also call explicit conversion functions (or implicit ones).
*/

#include <iostream>
using namespace std;

class Int {
	int x;

	public:
	Int(int x_in = 0)
		: x{ x_in }
	{
		cout << "Conversion Ctor called" << endl;
	}
	operator string()
	{
		cout << "Conversion Operator" << endl;
		return to_string(x);
	}
};

int main()
{
	// Example -1 
	float f = 3.5;
	int a = f; // this is how you do in C
	int b = static_cast<int>(f);
	cout << a << " " << b  << "\n"; // 3 3

	// Example -2
	char c = 'a';

	// pass at compile time, may fail at run time
	int* q = (int*)&c;
	// int* p = static_cast<int*>(&c);  // error: static_cast from 'char *' to 'int *' is not allowed

	/*
	   - This means that even if you think you can some how typecast a particular object int 
	   another but its illegal, static_cast will not allow you to do this.
	   */

	Int obj(3);
	string str = obj;
	obj = 20;
	string str2 = static_cast<string>(obj);
	obj = static_cast<Int>(30);
	/*
	   Output of above code:- 
	   Conversion Ctor called
	   Conversion Operator
	   Conversion Ctor called
	   Conversion Operator
	   Conversion Ctor called
	   */
	return 0;
}

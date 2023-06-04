/*
Inline variables:-
- The inline specifier can be applied to variables as well as to functions. 
- A variable declared inline has the same semantics as a function declared inline.
*/

#include <iostream>
using namespace std;

/*
- Before C++17, if your class had any non-const static data members, you had to 
  allocate memory for them. For example, suppose you have the following class definition:

class MyClass
{
private:
    static int s_anInt;
    static std::string s_aString;
};
Then your source file should contain the following:
int MyClass::s_anInt = 42;
std::string MyClass::s_aString = "Hello World!";
*/

/*
- In normal case static member inside class initialize outside of class.
- C++17 now supports inline variables which allow you to write the MyClass definition as follows:
*/
class MyClass
{
	public:
		static inline int s_anInt = 42;
		static inline std::string s_aString = "Hello World!";
};
int main()
{
	cout <<  MyClass::s_anInt << "\n";      // 42
	cout <<  MyClass::s_aString << "\n";    // Hello World!
	return 0;
}

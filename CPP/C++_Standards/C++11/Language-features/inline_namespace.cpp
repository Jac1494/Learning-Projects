/*
What Are inline Namespaces?
- C++11 introduced inline namespaces. They are namespaces that aren’t 
  really namespaces: Everything declared inside of them are also part.
  of the parent namespace.
*/

#include<iostream>
using namespace std;

namespace foo // normal namespace
{
	void foo_func(){
		cout << "foo_func\n";  
	} // function inside normal namespace
}

inline namespace bar // inline namespace
{
	void bar_func(){
		cout << "bar_func\n";
	} // function inside inline namespace
}

int main(){

	foo::foo_func(); // okay
	bar::bar_func(); // also okay

	//foo_func(); // error, no such function
	bar_func(); // okay, inline namespace!

	return 0;    
}

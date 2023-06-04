/*
   std::make_unique:-
   - std::make_unique is the recommended way to create instances of std::unique_ptrs due to the following reasons:

   1. Avoid having to use the new operator.
   2. Prevents code repetition when specifying the underlying type the pointer shall hold.
   3. Most importantly, it provides exception-safety. Suppose we were calling a function foo like so:

   foo(std::unique_ptr<T>{new T{}}, function_that_throws(), std::unique_ptr<T>{new T{}});

*/

//C++14
#include <iostream>
#include <memory>
using namespace std;

class T {};
int function_that_throws() { return 0;}

void foo(std::unique_ptr<T> v1, int v2,std::unique_ptr<T> v3) {}

int main(){

	foo(std::unique_ptr<T>{new T{}}, function_that_throws(), std::unique_ptr<T>{new T{}});    
	/*
	   - The compiler is free to call new T{}, then function_that_throws(), and so on... Since we 
	   have allocated data on the heap in the first construction of a T, we have introduced a leak here. 
	   With std::make_unique, we are given exception-safety:
	   */
	foo(std::make_unique<T>(), function_that_throws(), std::make_unique<T>());

	return 0;
}

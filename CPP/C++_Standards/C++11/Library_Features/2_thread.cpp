/*
std::forward:-
- Returns the arguments passed to it while maintaining their value category and 
  cv-qualifiers. Useful for generic code and factories. Used in conjunction with 
  forwarding references.
*/

// thread example option "-std=c++11 -pthread"
#include <iostream>       // std::cout
#include <thread>         // std::thread

void foo() 
{
	std::cout << "foo called\n";
}

void bar(int x)
{
	std::cout << "bar called\n";
}

int main() 
{
	std::thread first (foo);     // spawn new thread that calls foo()
	std::thread second (bar,0);  // spawn new thread that calls bar(0)

	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";

	return 0;
}
/*
foo called
main, foo and bar now execute concurrently...
bar called
foo and bar completed.
*/

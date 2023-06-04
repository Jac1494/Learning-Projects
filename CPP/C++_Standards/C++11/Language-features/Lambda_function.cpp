// A lambda is an unnamed function object capable of capturing variables in scope.
// Check with clang 3.8 without -std=c++11
#include<iostream>
#include<vector>
#include <cstdio>
#include <locale>
#include <algorithm>
#include <string.h>

using namespace std;

template<typename func>
void filter(func f, vector<int> v) {
	for (auto i : v) {
		if(f(i))
			cout << i << " ";
	}
}

int main(){
/*
 * Lambda function:-
 * - In Lambda function we pass [] variable is called capture.
 *   For example ([x]()) in this x is capture. It is known as last seen variable
 *   What we pass in () is function parameter 
 *   -> = it is return type
 *
 * Lambda capture:-
 * 1. [var] => capture var by value
 * 2. [&var] => capture var by reference
 * 3. [=] => capture all variable by value
 * 4. [&] => capture all variable by reference
 * 5. [&, var] => capture all reference , except capture var by value
 * 6. [&var, var2] => capture var by reference and var2 by value
 * 7. [this] - capture this by reference
 *
 */

	//Syntax - 1 
	cout << [](int x,int y)->int { return x+y; } (1,2) << endl; //Output - 3

	//C++ 20
	cout << []<typename T>(T x,T y)->T { return x+y; } (1,2) << endl; //Output - 3

	//Syntax - 2 
	auto f = [](int x,int y) { return x+y;};
	cout << f(1,2) << endl; //Output - 3

	vector<int> v = {1,2,3,4,5,6};

	filter([] (int x) { return (x>3);} ,v ); // Output - 4 5 6

	filter([] (int x) { return (x>2 && x<5);} ,v ); // Output - 3 4

	int y=4;
	filter([&] (int x) { return (x>y);} ,v ); // Output - 5 6 
						  // Note: [&] tells compiler that we want variable capture

						  // Application or usecase of lambda function
	cout << "\n";
	constexpr size_t _maxlen = 128;
	char s[] = "big light in sky slated to appear in east";

	char lastc = 0;
	transform( s, s + strnlen(s, _maxlen), s, [&lastc] (const char & c) -> char {
			const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
			lastc = c;
			return r;
			} );
	puts(s);

	int x = 1;

	auto f1 = [&x] { x = 2; }; // OK: x is a reference and modifies the original

	//auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value
				  // vs.
	auto f3 = [x]() mutable { x = 2; }; // OK: the lambda can perform any operations on the captured value

	return 0;
}

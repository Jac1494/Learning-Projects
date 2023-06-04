/*
Forwarding references:-
- Also known (unofficially) as universal references.
- Forwarding references allow a reference to bind to either 
  an lvalue or rvalue depending on the type. Forwarding references follow the rules of reference collapsing:

  1. T& & becomes T&
  2. T& && becomes T&
  3. T&& & becomes T&
  4. T&& && becomes T&&

- Example
    int x = 0; // `x` is an lvalue of type `int`
    auto&& al = x; // `al` is an lvalue of type `int&` -- binds to the lvalue, `x`
    auto&& ar = 0; // `ar` is an lvalue of type `int&&` -- binds to the rvalue temporary, `0`
*/

#include<iostream>
#include <vector>
using namespace std;

// Since C++11 or later:
template <typename T>
void f(T&& t) {
	cout << "r value \n";
}

template <typename T>
void f(T& t) {
	cout << "l value \n";
}

int main(){

	int x = 0;
	f(0); // T is int, deduces as f(int &&) => f(int&&)     // r value
	f(x); // T is int&, deduces as f(int& &&) => f(int&)    // l value

	int& y = x;
	f(y); // T is int&, deduces as f(int& &&) => f(int&)    // l value

	int&& z = 0; // NOTE: `z` is an lvalue with type `int&&`.
	f(z); // T is int&, deduces as f(int& &&) => f(int&)    // l value
	f(std::move(z)); // T is int, deduces as f(int &&) => f(int&&)  // r value
	return 0;    
}

/*
Converting constructors:-
- Converting constructors will convert values of braced list syntax 
  into constructor arguments.
*/

#include<iostream>
#include <vector>
using namespace std;

struct A {
	A(int) {cout << "A(int)\n"; }
	A(int, int) {cout << "A(int, int)\n";}
	A(int, int, int) {cout << "A(int , int, int)\n";}
};

struct B {
	B(int) {cout << "B(int)\n";}
	B(int, int) {cout << "B(int , int)\n";}
	B(int, int, int) {cout << "B(int , int, int)\n";}
	B(std::initializer_list<int>) {cout << "B(initializer_list)\n";}
};

int main(){

	A a {0, 0}; // calls A::A(int, int)
	A b(0, 0); // calls A::A(int, int)
	A c = {0, 0}; // calls A::A(int, int)
	A d {0, 0, 0}; // calls A::A(int, int, int)

	B a1 {0, 0}; // calls B::B(std::initializer_list<int>)
	B b1(0, 0); // calls B::B(int, int)
	B c1 = {0, 0}; // calls B::B(std::initializer_list<int>)
	B d1 {0, 0, 0}; // calls B::B(std::initializer_list<int>)

	return 0;    
}

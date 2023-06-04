/*
Template argument deduction for class templates:-
- Automatic template argument deduction much like how it's done for functions, 
  but now including class constructors.
*/

#include <iostream>
using namespace std;

template <typename T = float>
struct MyContainer {
	T val;
	MyContainer() : val{} {}
	MyContainer(T val) : val{val} {}

};

int main()
{
	MyContainer c1 {1}; // OK MyContainer<int>
	MyContainer c2; // OK MyContainer<float>

	cout << c1.val << "\n";         // 1 
	cout << c2.val << "\n";         // 0

	return 0;
}

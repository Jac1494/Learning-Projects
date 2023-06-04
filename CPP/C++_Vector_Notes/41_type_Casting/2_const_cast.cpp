/*
1. const_cast
- const_cast is used to cast away the constness of variables. Following are 
  some interesting facts about const_cast.
*/

#include <iostream>
using namespace std;

class student
{
private:
	int roll;
public:
	// constructor
	student(int r):roll(r) {}

	// A const function that changes roll with the help of const_cast
	void fun() const
	{
		( const_cast <student*> (this) )->roll = 5;
	}

	int getRoll() { return roll; }
};

int fun(int* ptr)
{
    return (*ptr + 10);
}
int fun2(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}
int main(void)
{
	student s(3);
	cout << "Old roll number: " << s.getRoll() << endl;  // 3

/* 
  1) const_cast can be used to change non-const class members inside a const member 
     function. Consider the following code snippet. Inside const member function fun(), 
     ‘this’ is treated by the compiler as ‘const student* const this’, i.e. ‘this’ is 
     a constant pointer to a constant object, thus compiler doesn’t allow to change 
     the data members through ‘this’ pointer. const_cast changes the type of ‘this’ pointer to ‘student* const this’.
*/

	s.fun();
	cout << "New roll number: " << s.getRoll() << endl;  // 5

/*
  2) const_cast can be used to pass const data to a function that doesn’t receive 
     const. For example, in the following program fun() receives a normal pointer, 
     but a pointer to a const can be passed with the help of const_cast.
*/
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    cout << fun(ptr1) << "\n";  // 20

/*
  3) const_cast is considered safer than simple type casting. It’safer in the sense 
     that the casting won’t happen if the type of cast is not same as original object. 
     For example, the following program fails in compilation because ‘int *’ is being 
     typecasted to ‘char *’
*/
    int a1 = 40;
    const int* b1 = &a1;
    // char* c1 = const_cast <char *> (b1); // compiler error
    // *c1 = 'A';

/*
  4) const_cast can also be used to cast away volatile attribute. For example, in the 
     following program, the typeid of b1 is PVKi (pointer to a volatile and constant integer) 
     and typeid of c1 is Pi (Pointer to integer)
*/
    int a2 = 40;
    const volatile int* b2 = &a2;
    cout << "typeid of b2 " << typeid(b2).name() << '\n';   // typeid of b2 PVKi
    int* c2 = const_cast <int *> (b2);
    cout << "typeid of c2 " << typeid(c2).name() << '\n';   // typeid of c2 Pi

	return 0;
}

/*
auto vs decltype:-
================
- decltype gives the declared type of the expression that is passed to it. 
  auto does the same thing as template type deduction. 
- So, for example, if you have a function that returns a reference, auto will 
  still be a value (you need auto& to get a reference), but decltype will be 
  exactly the type of the return value.
- Functions can also deduce the return type using auto. In C++11, a return type 
  must be specified either explicitly, or using decltype like so:
*/

#include <iostream>
int global{};
int& foo()
{
   return global;
}

template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {     
    // return type will be greater type size form from x and y
  return x + y;
}

int main()
{
    // ================ Example 1 ===================
    decltype(foo()) a = foo(); //a is an `int&`
    auto b = foo(); //b is an `int`
    b = 2;

    std::cout << "a: " << a << '\n'; //prints "a: 0"
    std::cout << "b: " << b << '\n'; //prints "b: 2"

    std::cout << "---\n";
    decltype(foo()) c = foo(); //c is an `int&`
    c = 10;

    std::cout << "a: " << a << '\n'; //prints "a: 10"
    std::cout << "b: " << b << '\n'; //prints "b: 2"
    std::cout << "c: " << c << '\n'; //prints "c: 10"

    // ================ Example 2 ===================

    const int var = 10;
    std::cout << var << "\n";       // 10

    auto r =var;
    r=11;
    std::cout << r << "\n";         // 11
    decltype(auto) r1 =var;
    // r1= 22;  // It will give error ,becuae we can't change value of const qualifier

    std::cout << add(1, 2) << "\n"; // == 3
    std::cout << add(1, 2.0) << "\n"; // == 3
    std::cout << add(1.5, 1.5) << "\n"; // == 3

    return 0;
}
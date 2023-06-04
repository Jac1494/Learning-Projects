/*
constexpr virtual functions:-
- Virtual functions can now be constexpr and evaluated at compile-time. 
  constexpr virtual functions can override non-constexpr virtual functions and vice-versa.
*/

#include <iostream>
// Well the obvious benefit is that you can even do 
// virtual function calls at compile time now.
struct Base {
    constexpr virtual int get() { return 1; }
    virtual ~Base() = default;
};

struct Child : Base {
    constexpr int get() override { return 2; }
    virtual ~Child() = default;
};

constexpr int foo(bool b) {
    Base* ptr = b ? new Base() : new Child();
    auto res = ptr->get(); // this call is not possible prior to C++20
    delete ptr;

    return res;
}

int main()
{
constexpr auto BaseVal = foo(true);
constexpr auto ChildVal = foo(false);

std::cout << "BaseVal => " << BaseVal << "\n";      // 1
std::cout << "ChildVal => " << ChildVal << "\n";    // 2
return 0;
}
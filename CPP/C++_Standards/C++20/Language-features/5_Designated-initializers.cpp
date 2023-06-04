/*
Designated initializers:-
- C-style designated initializer syntax. Any member fields that are not 
  explicitly listed in the designated initializer list are default-initialized.
// Looks like not c++20 feature
*/
#include <iostream>
struct A {
  int x;
  int y;
  int z = 123;
};

int main()
{
    A a {.x = 1, .z = 2};  
    std::cout << a.x << " " << a.y << " " << a.z << "\n"; // 1 0 2

    return 0;
}
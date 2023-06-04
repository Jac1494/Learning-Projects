https://github.com/AnthonyCalandra/modern-cpp-features#fallthrough-nodiscard-maybe_unused-attributes
https://blog.tartanllama.xyz/c++17-attributes/
------------------------------------------------------------------------------------------------------------------
[[fallthrough]], [[nodiscard]], [[maybe_unused]] attributes:-
C++17 introduces three new attributes: [[fallthrough]], [[nodiscard]] and [[maybe_unused]].

------------------------------------------------------------------------------------------------------------------
[[fallthrough]] indicates to the compiler that falling through in a switch statement is intended behavior. 
This attribute may only be used in a switch statement, and must be placed before the next case/default label.
switch (n) {
  case 1: 
    // ...
    [[fallthrough]];
  case 2:
    // ...
    break;
  case 3:
    // ...
    [[fallthrough]];
  default:
    // ...
}
------------------------------------------------------------------------------------------------------------------
[[nodiscard]] issues a warning when either a function or class has this attribute and its return value is discarded.
[[nodiscard]] bool do_something() {
  return is_success; // true for success, false for failure
}

do_something(); // warning: ignoring return value of 'bool do_something()',
                // declared with attribute 'nodiscard'
// Only issues a warning when `error_info` is returned by value.
struct [[nodiscard]] error_info {
  // ...
};

error_info do_something() {
  error_info ei;
  // ...
  return ei;
}

do_something(); // warning: ignoring returned value of type 'error_info',
                // declared with attribute 'nodiscard'
------------------------------------------------------------------------------------------------------------------				
[[maybe_unused]] indicates to the compiler that a variable or parameter might be unused and is intended.
#include <iostream>
using namespace std;

// compare gcc 6.4 vs gcc 7.1
int main()
{
    int x=88;
    [[maybe_unused]] int y=99;
    cout << " x - " << x << "\n";
    return 0;
}
------------------------------------------------------------------------------------------------------------------

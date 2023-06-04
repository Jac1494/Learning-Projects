/*
std::apply:-
Invoke a Callable object with a tuple of arguments.
*/

#include <functional>
#include <iostream>

using namespace std;

auto add = [](int x, int y) {
  return x + y;
};
 
int main()
{
    cout << std::apply(add, std::make_tuple(1, 2)) << "\n"; 
    return 0;
}

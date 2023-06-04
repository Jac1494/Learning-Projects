/*
Type aliases:-
- Semantically similar to using a typedef however, type aliases with 
  using are easier to read and are compatible with templates.
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using Vec = std::vector<T>;
Vec<int> v; // std::vector<int>

using String = std::string;
String s {"foo"};

int main()
{
    v.push_back(9);

    cout << "Vector element -> " << v.at(0) << "\n";        // 9
    cout << "String -> " << s << "\n";                      // foo
    return 0;
}
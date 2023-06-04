/*
std::to_string:-
- Converts a numeric argument to a std::string.
*/

#include <iostream>
using namespace std;
 
int main()
{
    cout << std::to_string(1.2) << "\n"; //  "1.200000"
    cout << std::to_string(123) << "\n"; //  "123"
    return 0;
}
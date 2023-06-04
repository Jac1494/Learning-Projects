/*
Range-based for loops:- 
- Syntactic sugar for iterating over a container's elements.
*/

#include<iostream>
#include<array>
using namespace std;

void print(std::array<int, 5> a)
{
    cout << "Array element -> ";
    for (int x : a) 
    cout << x << " ";

    cout << "\n";
}
int main(){

    std::array<int, 5> a {1, 2, 3, 4, 5};
    for (int x : a) 
    {
        x *= 2;
    }
    print(a);   // 1 2 3 4 5

    for (int& x : a) 
    {
        x *= 2;
    }
    print(a);  // 2 4 6 8 10

    return 0;
}
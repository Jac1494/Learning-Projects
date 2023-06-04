/*
Lambda capture of parameter pack:-
*/

#include <iostream>
// Capture parameter packs by value:
template <typename... Args>
auto f1(Args&&... args){
    // BY VALUE:
    return [...args = std::forward<Args>(args)] { //warning: initialized lambda pack captures are a C++20 extension [-Wc++20-extensions]
    };
}

//Capture parameter packs by reference:
template <typename... Args>
auto f2(Args&&... args){
    // BY REFERENCE:
    return [&...args = std::forward<Args>(args)] { //warning: initialized lambda pack captures are a C++20 extension [-Wc++20-extensions]
    };
}

int main()
{
    return 0;
}
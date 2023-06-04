/*
Range-based for loop with initializer:-
- This feature simplifies common code patterns, helps keep scopes tight, 
  and offers an elegant solution to a common lifetime problem.

// https://ggulgulia.medium.com/c-20-range-based-for-loop-with-initializer-statement-2516782a7c3f#:~:text=In%20C%2B%2B20%20the%20limitation%20of%20specifying%20a%20loop,the%20following%20syntax%20for%20%28intitialization-expression%20%28optional%29%3B%20range-declaration%3A%20range%29  
 */
#include <iostream>
using namespace std;

void print(auto &var)       // C++ 20 feature
{
    cout << "Value - " << var << "\n";
}

int main(){
    int x=99;
    print(x);           // 99
    return 0;   
}

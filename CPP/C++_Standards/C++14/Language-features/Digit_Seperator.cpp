// Digit Seperator

/*
 * 1. Now there is a better code readability with Digit Seperator.
 * 2. We use single quotation mark (') for as a Digit Seperator.
 * 3. Why ' for Digit Seperator why not something else? 
 * -> for function call foo(100,000) it will consider as arguent so create a issue that's why used (')
 */

#include<iostream>
using namespace std;

// Check with C++14 option and clang 5.0.1
int main(){
  auto x = 1'000'000;
  cout << x << endl;
  return 0;
}

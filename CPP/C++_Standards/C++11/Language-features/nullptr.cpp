// Check with clang 3.8 without -std=c++11
#include<iostream>
#include<vector>
using namespace std;

/*
 * nullptr
 *
 * To replace NULL(which represent as integer 0) in C++03
 */

void foo(int i) {
   cout << "foo_int" << endl;
}

void foo(char *p) {
   cout << "foo_char*" << endl;
}

int main(){

   //foo(NULL); // Ambiguous

   foo(nullptr); // foo_char*
}

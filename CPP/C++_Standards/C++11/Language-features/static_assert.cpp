// Check with clang 3.8 without -std=c++11
#include<iostream>
#include<cassert>
using namespace std;

int main(){

//static_assert 

int *p=NULL;

// run-time assert
assert(p!=NULL); 

// Compile time assert
static_assert(sizeof(int)==4, "size error"); //C++11

}

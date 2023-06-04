/*
Delegating constructors:-
- Constructors can now call other constructors in the same class using an initializer list.
*/
#include<iostream>
#include<cassert>
using namespace std;

/*
 * Delegating Constructor
 *
 */

// C++ 03
// class A {
//  public:
//  void foo() { cout << "foo" << endl;} 
//  void fun() { cout << "fun" << endl;} 

//  A() { 
//    foo();
//  }
 
//  A(int num) {
//    foo();
//    fun();
//  }
// };
/* Cons:-
 * 1. Cumbersome code.
 * 2. foo() could be invoked by other functions.
*/

// C++ 11
class A {
 public:
 
 int var=11; // In Class variable initialization is also C++ 11 feature
 void foo() { cout << "foo" << endl;} 
 void fun() { cout << "fun" << endl;} 

 A() { 
   foo();
 }
 
 A(int num) : A() {
   fun();
 }
};
// Limitation : A() has to be called first

int main(){
  
  A a;
  A b(1);

}
/*
Output:-
======
foo
foo
fun
*/



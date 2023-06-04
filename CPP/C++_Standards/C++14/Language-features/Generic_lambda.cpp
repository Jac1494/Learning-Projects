/*
Generic lambda:-
- Note in C++14 we have Generics/Polymorphic lambda.
*/

#include<iostream>
using namespace std;

int factory(int i) { return i * 10; }

// Check latest compiler version with C++11 , it will give warning

int main(){
   auto add =[] (auto x,auto y) { return x+y; };
   
   int a=1 , b=2;
   std::string str1="Hello" , str2="World";

   cout << add(a,b) << endl;        // 3
   cout << add(str1,str2) << endl;  // HelloWorld

/*
Lambda capture initializers:-
- This allows creating lambda captures initialized with arbitrary expressions.
- The name given to the captured value does not need to be related to any variables 
  in the enclosing scopes and introduces a new name inside the lambda body.
*/
   // Example - 1
   auto f1 = [x = factory(2)] { return x; };
   cout << f1() << "\n";  // 20

   // Example - 2
   auto newadd = [add = add(11,22)] () {
    // above add in left side of = is private member which can't be availble out side
    return add;
   };

   cout << newadd() << "\n";  // 33

   return 0;
}
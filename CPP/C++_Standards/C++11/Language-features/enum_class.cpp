/*
Strongly-typed enums:-
- Type-safe enums that solve a variety of problems with C-style enums including: 
  implicit conversions, inability to specify the underlying type, scope pollution.

- Example:-
  // Specifying underlying type as `unsigned int`
  enum class Color : unsigned int { Red = 0xff0000, Green = 0xff00, Blue = 0xff };
  // `Red`/`Green` in `Alert` don't conflict with `Color`
  enum class Alert : bool { Red, Green };
  Color c = Color::Red;
*/

#include<iostream>
using namespace std;

int main(){

// enum class
/*
// C++ 03
enum apple {green, red};
enum orange {big , small};
apple a = green;
orange o = big;

if(a==o)
  cout << " green apple and big orange are the same\n";
else
  cout << " green apple and big orange are not the same\n";
*/
// C++ 11


enum class apple {green, red};
enum class orange {big , small};
apple a = apple::green;
orange o = orange::big;

if(a==o)  //  Compile time error
  cout << " green apple and big orange are the same\n";
else
  cout << " green apple and big orange are not the same\n";

}

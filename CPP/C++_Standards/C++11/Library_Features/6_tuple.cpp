/*
Tuple:-
- A tuple is an object capable to hold a collection of elements. Each element 
  can be of a different type.
*/

// tuple example
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

int main ()
{
  std::tuple<int,char> foo (10,'x');
  auto bar = std::make_tuple ("test", 3.1, 14, 'y');

  std::get<2>(bar) = 100;                                    // access element

  int myint; char mychar;

  std::tie (myint, mychar) = foo;                            // unpack elements
  std::tie (std::ignore, std::ignore, myint, mychar) = bar;  // unpack (with ignore)

  mychar = std::get<3>(bar);

  std::get<0>(foo) = std::get<2>(bar);
  std::get<1>(foo) = mychar;

  std::cout << "foo contains: ";
  std::cout << std::get<0>(foo) << ' ';     // 100
  std::cout << std::get<1>(foo) << '\n';    // y

  std::tuple<int,char,float> tfoo (11,'A',1.1f);
  // std::pair<int,char,float> tpair (); //error only two argument will work.It is pair.

  return 0;
}

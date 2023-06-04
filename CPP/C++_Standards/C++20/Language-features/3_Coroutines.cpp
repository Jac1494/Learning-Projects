/*
Coroutines:-
- Coroutines are a new feature added in C++20 that allows suspending and resuming 
  a function at specific points, making it easy to implement asynchronous operations 
  and cooperative multitasking.
- To define a coroutine, the co_return, co_await, or co_yield keywords must be present 
- in the function's body. C++20's coroutines are stackless; unless optimized out by 
  the compiler, their state is allocated on the heap.

// https://medium.com/pranayaggarwal25/coroutines-in-cpp-15afdf88e17e
// https://github.com/AnthonyCalandra/modern-cpp-features#coroutines
*/
// TODO error need to resolved
#include <coroutine>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <compare>
#include <initializer_list>
#include <iterator>

template <typename T>
generator<int> range(T first, T last)
{
  while (first != last)
  {
    co_yield first++;
  }
}

int main()
{
  for (int i : range(0, 10))
  {
    printf("%d\n", i);
  }
}

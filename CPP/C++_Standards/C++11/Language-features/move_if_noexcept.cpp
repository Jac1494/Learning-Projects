/*
Move if noexcept:-
- Returns an rvalue reference to arg, unless copying is a better option than moving 
  to provide at least a strong exception guarantee.
- Also check option https://cplusplus.com/reference/utility/move_if_noexcept/ 
*/

#include <iostream>
#include <utility>
 
struct Bad
{
    Bad() {}
    Bad(Bad&&)  // may throw
    {
        std::cout << "Throwing move constructor called\n";
    }
    Bad(const Bad&) // may throw as well
    {
        std::cout << "Throwing copy constructor called\n";
    }
};
 
struct Good
{
    Good() {}
    Good(Good&&) noexcept // will NOT throw
    {
        std::cout << "Non-throwing move constructor called\n";
    }
    Good(const Good&) noexcept // will NOT throw
    {
        std::cout << "Non-throwing copy constructor called\n";
    }
};
 
int main()
{
    Good g;
    Bad b;
    Good g2 = std::move_if_noexcept(g);     // Non-throwing move constructor called
    Bad b2 = std::move_if_noexcept(b);      // Throwing copy constructor called
    return 0;
}
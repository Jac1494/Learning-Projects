#include <iostream>
using namespace std;
/*
- The statement "using namespace std;" specifies that the members defined in 
  the 'std' namespace will be used in the program very frequently.
*/

/*

NAMESPACE:-
- "It is declartive region used to localize global identifier names to avoid name collisions".
- Syntax:-
  namespace namespace_identifier
  {
      // definitions of variables, function and class , etc
  }
- It is used in LLVM class, C++ Standard Library
*/

namespace A{
    int x = 11;
}
// Namespace can be redefined any number of time.
namespace A{
    int y = 11;
}
namespace B{
    int x = 22;
    // Below one is also works fine. It will treat as seperate region.
    namespace A{
    int x = 11;
    }
}
namespace C = A; // we can able to copy one namespace into other.

int main()
{
   // using namespace A;  
   // Error Ambigues because below We have call namespace B , So now value of x will confused.
   // Solution is we need to create block 
   //{ using namespace A;
   //}
   {
    using namespace A;
   cout << "X in B " << x << "\n";      // 11
   }
   {
    using A::x;
    cout << "X in B " << x << "\n";      // 11
   }

   cout << "X in A " << A::x << "\n";   // 11
   cout << "X in B " << B::x << "\n";   // 22
   using namespace B;
   cout << "X in B " << x << "\n";      // 22
   cout << "X in C " << C::x << "\n";   // 11

/*
   namespace C{
    int x = 22;
    }
    // ERROR: namespace must be global only.
*/    
   return 0;
}


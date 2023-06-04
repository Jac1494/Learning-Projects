/*
Deprecate implicit capture of this:-
- Implicitly capturing this in a lambda capture using [=] is now deprecated; 
  prefer capturing explicitly using [=, this] or [=, *this].

*/

#include <iostream>
using namespace std;

#include <iostream>

struct  X {
    void  f()
    {
        int  value = 3;

        auto  x = [=] {         // Deprecated from C++20: 
            return  value + g(); 
        };

        auto  y = [=, this] {   // Recommended method from C++20: 
            return  value + g();  // [=] The this pointer will not be captured, so capture with specifying this 
        };
    }

    int g() const
    {
        return  2;
    }
};

int  main()
{
    X().f();
	return 0;
}


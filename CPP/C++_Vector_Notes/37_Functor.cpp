/*
Functors:-
- Consider a function that takes only one argument. However, while calling 
  this function we have a lot more information that we would like to pass 
  to this function, but we cannot as it accepts only one parameter. 
  What can be done?
- One obvious answer might be global variables. However, good coding practices 
  do not advocate the use of global variables and say they must be used only 
  when there is no other alternative.
- Functors are objects that can be treated as though they are a function 
  or function pointer. 
- Functors are most commonly used along with STLs in a scenario like following:

- "A functor (or function object) is a C++ class that acts like a function. 
  Functors are called using the same old function call syntax. 
  To create a functor, we create a object that overloads the operator().

The line,
MyFunctor(10);

Is same as
MyFunctor.operator()(10);
Let’s delve deeper and understand how this can actually be used in conjunction with STLs. 
*/

// C++ program to demonstrate working of
// functors.
#include <bits/stdc++.h>
using namespace std;
 
// A Functor
class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }
 
    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};
 
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;  // We can able add any number we want
 
    transform(arr, arr+n, arr, increment(to_add));
 
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

/* Example -2 

#include <cstdio>
using namespace std;

class MultBy {
    int mult = 1;
    MultBy();// a default constructor
public:
    MultBy ( int n ) : mult(n) {}
    int operator () ( int n ) const { return mult * n; }
};

int main() {
    const MultBy times4(4);
    const MultBy times10(10);
    const MultBy times15(15);
    printf("times4(5) is %d\n", times4(5));
    printf("times4(15) is %d\n", times4(15));
    printf("times10(5) is %d\n", times10(5));
    printf("times10(15) is %d\n", times10(15));
    printf("times15(5) is %d\n", times15(5));
    printf("times15(15) is %d\n", times15(15));
    return 0;
}
*/


#include<iostream>
using namespace std;

/*
Default Arguments:-
- Provide default value to argument , so if user not provide any value at time of function call
  it will take default value.
- Advantage is same function we can use for multiple purpose.  
- It is must be start from left.
- If default parameter must be given only in the function prototype and must not be repeated in the function defination.
*/

void print(int x,int y=11)
{  
    cout << "X - " << x ;   
    cout << " | Y - " << y <<  "\n";   
}

int main()
{
   print(11,22);   
   print(11);
   return 0;
}

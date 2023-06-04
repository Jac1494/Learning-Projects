#include<iostream>
using namespace std;

// Ambignity in function overloading:-
// - Sitution when compiler unable to choose proper one call/entiry between two
int main()
{

/*
// Case 1
    1. float fun(float);
    2. float fun(double);

    fun(22.7);
    fun(22.7f);
    fun(22);
*/    

/*
// Case 2
    1. int sum(int,int=0);
    2. int sum(int);

    sum(11,22);
    sum(11);
*/    

/*
// Case 3
    1. void fun(int x);
    2. void fun(int &x);

    int i;    
    fun(11);
    fun(i);
*/
   return 0;
}
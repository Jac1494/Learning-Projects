#include<iostream>
using namespace std;

// How to return value from constructor

class A
{
    public:
    A()
    {
        throw 10;
    }
};

int main(){

    int x;
    try
    {
        A ob;
    }
    catch(int x)
    {
        cout << "Value of X is " << x <<"\n";
    }

    return 0;
}


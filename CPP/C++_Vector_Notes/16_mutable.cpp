#include<iostream>
using namespace std;

/*
Mutable:-
- It is a keyword which is allowed a perticular data member of constant object to be modified.
*/

struct st{
mutable int x;
        int y;
};

int main()
{
   const st ST={11,22};
   cout << ST.x << " " << ST.y << "\n";         // 11 22 
   ST.x=99;
   cout << ST.x << " " << ST.y << "\n";         // 99 22
   return 0;
}

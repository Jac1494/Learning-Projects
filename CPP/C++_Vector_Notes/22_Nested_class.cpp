#include <iostream>
using namespace std;

class A{
public:
    int x;
    void setdata(int a)
    {
        x=a;
        b.y=22;
    }
    void print(){
      cout << "X - " << x << " | Y in A - " << b.y << "\n";
    }

    class B{
    public:
    int y;
    
        void print(){
        cout << "Y in B - " << y << "\n";
        }
        void setdata(int a)
        {
        y=a;
        }
    }b;     // TODO : How to call print() method using object.

}a;

int main()
{
   a.setdata(11);
   a.print();  // 11 22
 
   A::B ob;
   ob.setdata(33);
   ob.print();  // 33

   return 0;
}

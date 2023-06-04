#include <iostream>
using namespace std;

class COMPLEX{
    private:
    int real,imag;

    public:
    void setdata(int,int);
    void add1(COMPLEX &, COMPLEX &);
    COMPLEX add2(COMPLEX &);
    void print(void);
};
void COMPLEX::setdata(int a,int b)
{
    real=a;
    imag=b;
}
void COMPLEX::add1(COMPLEX &obj1,COMPLEX &obj2){
    real = obj1.real + obj2.real;
    imag = obj1.imag + obj2.imag;
}

COMPLEX COMPLEX::add2(COMPLEX &obj2){
    COMPLEX temp;
    temp.real = real + obj2.real;
    temp.imag = imag + obj2.imag;
    return temp;
}

void COMPLEX::print(void){
    cout << "real -> " << real << " imag -> " << imag << "\n";
}

int main()
{
   
   COMPLEX obj1,obj2,obj3;
   obj1.setdata(10,20);
   obj2.setdata(11,22);

   obj3.add1(obj1,obj2);  // 21 42
   obj3.print();

   obj3=obj1.add2(obj2);  // 21 42
    //obj3=obj1 + obj2;  // ERROR // TODO

   obj3.print();

   return 0;
}

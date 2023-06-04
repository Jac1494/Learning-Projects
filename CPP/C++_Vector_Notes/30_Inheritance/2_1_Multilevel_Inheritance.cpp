#include<iostream>
using namespace std;

//  Multilevel Inheritance

class A {

  protected:
  int v1,v2;

  public:

  A() { cout << "Constructor of A\n"; }
  ~A(){ cout << "Destructor of A\n";  }

  A(int q,int r):v1(q),v2(r){}
};

class B: protected A {    

  protected:
  int v3,v4;

  public:
  B() { cout << "Constructor of B\n"; }
  ~B(){ cout << "Destructor of B\n"   ;}

  B(int o,int p,int q,int r):v3(o),v4(p),A(q,r){}
};

class C: protected B {

  protected:
  int v5,v6;

  public:
  C() { cout << "Constructor of C\n"; }
  ~C(){ cout << "Destructor of C\n"; }

  C(int m,int n,int o,int p,int q,int r):v5(m),v6(n),B(o,p,q,r){}

/*
- We can able to access public and protected member of base class in 
  derived class , not private.
- We have created only paramaterise constructor of C class , So 
  only destructor's are call not constructor of any class.  
*/  
  void print_All()
  {  
    cout << "print A " << v1 << " " << v2 << "\n" ;
    cout << "print B " << v3 << " " << v4 << "\n" ;
    cout << "print C " << v5 << " " << v6 << "\n" ;
  }
};

int main(){

  C c(66,55,44,33,22,11);
  c.print_All();

  return 0;

}
/*
print A 22 11
print B 44 33
print C 66 55
Destructor of C
Destructor of B
Destructor of A
*/
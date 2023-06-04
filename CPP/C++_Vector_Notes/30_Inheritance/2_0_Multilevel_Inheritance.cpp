#include<iostream>
using namespace std;

//  Multilevel Inheritance

class A {

  private:
  int v1,v2;

  public:

  A() { cout << "Constructor of A\n"; }
  ~A(){ cout << "Destructor of A\n";  }

  A(int q,int r):v1(q),v2(r){}

  void print_A()
  {
    cout << "print A " ;
    cout << v1 << " " << v2 << "\n" ;
  }
};

// NOTE:-
//class B:private A {  // ERROR
// In C we are accessing print A which we inherited private in B
// If we call print_A(); in print_B() instead of print_C() then 
// It will get visiblity and it will works

class B: protected A {    

  private:
  int v3,v4;

  public:
  B() { cout << "Constructor of B\n"; }
  ~B(){ cout << "Destructor of B\n"   ;}

  B(int o,int p,int q,int r):v3(o),v4(p),A(q,r){}

  void print_B()
  {
    cout << "print B " ;
    cout << v3 << " " << v4 << "\n" ;
  }
};

class C: protected B {

  private:
  int v5,v6;

  public:
  C() { cout << "Constructor of C\n"; }
  ~C(){ cout << "Destructor of C\n"; }

  C(int m,int n,int o,int p,int q,int r):v5(m),v6(n),B(o,p,q,r){}
  
  void print_C()
  {
    print_A();    
    print_B();
    cout << "print C " ;
    cout << v5 << " " << v6 << "\n" ;
  }
};

int main(){

  C c(66,55,44,33,22,11);
  c.print_C();
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

#include<iostream>
using namespace std;

/*
Virtual Base class:-
- The virtual base class are used to avoid duplication of data.
*/
//  Multipath Inheritance
class A {

  protected:
  int v1,v2;

  public:

  A() { cout << "Constructor of A\n"; }
  ~A(){ cout << "Destructor of A\n";  }

  A(int s,int t):v1(s),v2(t){}
};

class B: virtual protected A {    

  protected:
  int v3,v4;

  public:
  B() { cout << "Constructor of B\n"; }
  ~B(){ cout << "Destructor of B\n";  }

  B(int q,int r):v3(q),v4(r){}
};

class C: virtual protected A {

  protected:
  int v5,v6;

  public:
  C() { cout << "Constructor of C\n"; }
  ~C(){ cout << "Destructor of C\n"; }

  C(int o,int p):v5(o),v6(p){}
};

class D: protected B,protected C {

  protected:
  int v7,v8;

  public:
  D() { cout << "Constructor of D\n"; }
  ~D(){ cout << "Destructor of D\n"; }

  // D(int m,int n,int o,int p,int q,int r,int s,int t):v7(m),v8(n),B(o,p,s,t),C(q,r,s,t){}  // This will not we got grabage value for class A member
  D(int m,int n,int o,int p,int q,int r,int s,int t):v7(m),v8(n),A(s,t),B(o,p),C(q,r){}
  
  void print_ALL()
  {
    cout << v1 << " " << v2 << "\n" ;
    cout << v3 << " " << v4 << "\n" ;
    cout << v5 << " " << v6 << "\n" ;
    cout << v7 << " " << v8 << "\n" ;
  }
};

int main(){

  D d(88,77,66,55,44,33,22,11);
  d.print_ALL();
  return 0;

}
/*
- If we not provide virtual then we get below error

<source>:55:13: error: non-static member 'v1' found in multiple base-class subobjects of type 'A':
    class D -> B -> A
    class D -> C -> A
    cout << v1 << " " << v2 << "\n" ;
            ^
<source>:8:7: note: member found by ambiguous name lookup
  int v1,v2;
      ^

output:-

22 11
66 55
44 33
88 77
Destructor of D
Destructor of C
Destructor of B
Destructor of A
*/


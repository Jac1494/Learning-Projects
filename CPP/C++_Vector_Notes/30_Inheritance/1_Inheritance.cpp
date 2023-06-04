/*
Inheritance:-
- "Inheritance is the preocess of acquiring the propeties of one class into
another class."
- Adtanvatage of inheritance is reusabiltiy;
- We can create common feature in base class and only update required 
  feature in derived class , this will improve code size. Instead of 
  writing all method seperate.

Features:-
- Derived class automatically inherit the features of the base class.
  Also it may add additional features. Apart from those inherited from 
  the base classes.
- Even through Constructor and Destructors can't be inherited , the derived class
  will call the constructors and destructors.
- In inheritance base class Constructor is called first then derived class.
  And Destructor is called in reverse order.

-----------------------------------------------
Base class |   Derived class visibility       |
Visibilty  |  public   |  protected | private |
----------------------------------------------|
public     |  public   |  protected | private |
----------------------------------------------|
protected  | protected |  protected | private |
----------------------------------------------|
private    |<------can't be inhritaned------->|
----------------------------------------------|

Types of Inheritance
====================
1. Single Inheritance
->    A
      |
      B

2. MultiLevel Inheritance
->    A
      |
      B
      |
      C

3. Multiple Inheritance
->    A       B       C
      |       |       |       
      |-------|-------|
              D
       
4. Hieractical Inheritance
->            A       
      |-------|-------|
      |       |       |       
      B       C       D
      
5. Hybrid Inheritance
->    A
      |
      B       C
      |-------|
          |
          D

6. Multipath Inheritance
->        A    
          |
      |-------|
      B       C
      |-------|
          |
          D
*/

#include<iostream>
using namespace std;

class A {

  public:
  A(){
    cout << "Constructor of A\n";
  }
  ~A(){
    cout << "Destructor of A\n";
  }
};

class B: public A {

  public:
  B(){
    cout << "Constructor of B\n";
  }
  ~B(){
    cout << "Destructor of B\n";
  }
};

int main(){

  A a; 
  /*  // Only for A a;
    Constructor of A
    Destructor of A  
  */ 
  B b;
  /*  // Only for B b;
    Constructor of A
    Constructor of B
    Destructor of B
    Destructor of A
  */
  return 0;
}
/*
Constructor of A
Constructor of A
Constructor of B
Destructor of B
Destructor of A
Destructor of A
*/

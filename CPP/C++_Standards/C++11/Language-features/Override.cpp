// Check with clang 3.8 without -std=c++11
#include<iostream>
using namespace std;

/*
 *  Override:-
 *  
 * To avoid inadvertently create new function in deriver class
 */

// C++ 03

// class Base {
//     virtual void A(int);
//     virtual void B() const;
//     void C();
// };

// class Deriver : public Base {

//     virtual void A(float); // Arugument is float so created a new function
//     virtual void B() ; // Const is missed so created a new function
// };

// C++ 11

class Base {
    virtual void A(int);
    virtual void B() const;
};

class Deriver : public Base {
    virtual void A(float) override; // error: 'A' marked 'override' but does not override any member functions
    virtual void B() override;      // 'B' marked 'override' but does not override any member functions
};

int main(){
}




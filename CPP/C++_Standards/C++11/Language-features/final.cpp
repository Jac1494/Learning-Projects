/*
 * final (for virtual function and for class)
 *
 */
// C++ 11

// 1.No class can be derived from base

class Base1 final{};
class Deriver1 : public Base1 {}; // error: base 'Base1' is marked 'final'

// 2.No class can be derived from base

class Base2 {
   virtual void A() final;
};
class Deriver2 : public Base2 {
    void A(); // error: declaration of 'A' overrides a 'final' function 
};

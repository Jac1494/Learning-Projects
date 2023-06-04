/*
Deleted functions:-
- A more elegant, efficient way to provide a deleted implementation of a function. 
  Useful for preventing copies on objects. 
*/

// class A{
//   public:
//   A(int num) {}
// };

// A a1(1);
// A a2(2.0);  // 2.0 is converted from double to int 


// C++ 11

class A{
  public:  
  A(int num) {}
  A(double)= delete;  
};

 A a1(1);
 A a2(2.0);  // error: call to deleted constructor of 'A'

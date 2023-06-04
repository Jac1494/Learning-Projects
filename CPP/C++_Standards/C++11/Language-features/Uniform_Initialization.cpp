// Check with clang 3.8 without -std=c++11
#include<iostream>
using namespace std;

//C++ 03 
class A1{    // Aggregate class or struct
   public:
      int age;
      string name;  
};

A1 a11= {11 , "Hello"}; // Aggregate Initialization

// C++ 11 exteded the scope of curly brace initialization

class A2{
   public:
     A2(int age,string name) {} 
};

A2 a21= {11 , "Hello"}; 


/* 
 * Uniform Initialization search Order:-
 * 1. Initializer_list constructor
 * 2. Regular constructor that takes the appropriete parameters.
 * 3. Aggregate initializer.
 */

class B{
   public:		                     // 3rd choice 
   int age;

   B(int a){                         // 2rd choice 
      age =a;
   }

   B(const initializer_list<int>& v){ // 1st choice 
       age = *(v.begin());
   }
};

B b{11};

int main(){

}

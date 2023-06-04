/ 
 *  C++ 11: Rvalue Reference
 *  
 *  1. Moving Semantics
 *  2. Perfect Forwarding
 * /
 
// What is rvalue refrence?

int a = 5;  // a is a lvalue
int& b = a; // b is a lvalue reference
int&& c;    // c is a rvalue reference

// How to use:

void printInt(int& i) { cout << "lvalue refernce : " << i << endl; }
void printInt(int&& i) { cout << "rvalue refernce : " << i << endl; }
void printInt(int i) {} // Error for both a and 6; Only overload function with lvalue or rvalue

int main(){
int a = 5;  // a is a lvalue
printInt(a); // Call printInt(int& i)
printInt(6); // Call printInt(int&& i)
}


// What is real use case rvalue.

class A{
   int size;
   double* arr;  // A big array

public:
   A(const A& rhs) { // Copy constructor (costly deep copy)
     size = rhs.size;
     arr = new double[size];
     for(int i=0;i<size;i++) { arr[i] = rhs.arr[i]; }
    }

   A(const A&& rhs) { // Move constructor
     size = rhs.size;
     arr = rhs.arr;
     rhs.arr = nullptr;
    }

   ~A() { delete arr; }
};

void foo(A v);

A createA(); // Create a A

int main(){
   A reusable = createA();
   foo(reusable);  // Copy Constructor and it is costly one but reusable used later so ok

   foo(createA()); // createA() return rvalue and it will distroy. no point to make copy and pass to foo

}

/*
 * Note 1: the most useful place for rvalue reference is overloading copy 
 * constructor and copy assignment operator , to achieve move semantics
 */
X& X::operator=(X const & rhs);
X& X::operator=(X&& rhs);

/*
 * Note 2: Move semantics is implemented for all STL containers , which means: 
 *    a. Move to C++ 11 , You code will be faster without changing a thing.
 *    b. passing-by-value can be used for STL containers
 */

vector<int> foo() {
  // ...
  return myvector;
}

void hoo(string s);
bool goo(vector<int>& arg); // Pass by reference if you use arg to carry 
 			    // data back from goo()

/*
 * Summary:
 * Move Constructor/ Move Assignment Operator:
 *   Purpose: cpnveniently avoid costly and unnecessary deep copying
 *   
 * 1. They are particularly powerful where passing by reference and passing by value are both used
 *
 * 2. They give you finer control of which part of your object to be moved.
 */
 

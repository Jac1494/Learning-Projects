/*
Move semantics:-
- Moving an object means to transfer ownership of some resource it manages to another object.
- Moves also make it possible for non-copyable types such as std::unique_ptrs (smart pointers) 
  to guarantee at the language level that there is only ever one instance of a resource being managed 
  at a time, while being able to transfer an instance between scopes.
*/
#include<iostream>
#include <vector>
using namespace std;
/*
 *  l value reference not work for move
 *  r value reference can move. So we use r value for move 
 */

class A
{
   public:
   A(){ cout <<" Default Constructor" << endl;}
   A(const A&){ cout <<" Copy Constructor" << endl;}
   A(const A&&){ cout <<" Move Constructor" << endl;}

   // noexcept -> prevent source object to be unknown state
   A& operator =(A& obj1) noexcept{
       cout <<" Copy assign" << endl;
       return obj1;
   }
   A& operator =(A&& obj2){
       cout <<" Move assign" << endl;
       return obj2;
   }
}; 
void printVector(vector<int>& v)
{
    cout << "Vector =>  size = " << v.size() ;
    cout << " Elements = " ;

    for(auto it=v.begin();it!=v.end();it++)
    cout << " " << *it ;
    cout << "\n" ;

}

template< typename T >
void swap ( T &a , T &b)
{
	puts("Swap()");
	T _temp(std::move(a));
	a = std::move(b);
	b = std::move(_temp);
}

// Special member function for move semantics

A f(A a) {
  return a;                     // Default Constructor
}

int main(){
  
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={11,22,33,44,55};

    printVector(v1); // Vector =>  size = 5 Elements =  1 2 3 4 5
    printVector(v2); // Vector =>  size = 5 Elements =  11 22 33 44 55

    // To use above swap function instead of standard library function
    //  we need to call as ::swap(v1,v2);
    //  :: means it will refer in current scope
    ::swap(v1,v2);
    ::swap(v1,v2); // Only add so no need to change below code.

    v1=std::move(v2);
    printVector(v1); // Vector =>  size = 5 Elements =  11 22 33 44 55
    printVector(v2); // Vector =>  size = 0 Elements = 

    A a;                        // Default Constructor
    A b=a;                      // Copy Constructor 
    A c=std::move(b);           // Move Constructor
    A d(static_cast<A&&>(a));   // Move Constructor

    d=c;                        // Copy assign
    d=std::move(c);             // Move assign
    d=static_cast<A&&>(c);      // Move assign

    // std::move internally just r value cast to object
    // So we can able to write as per below, But better to follow standard syntax
    A v3=(A &&)v2;              // Move Constructor
    
    A v4=f(A{});                // Move Constructor

    return 0;    
}
/*
Non-static data member initializers:-
- Allows non-static data members to be initialized where they are declared, 
  potentially cleaning up constructors of default initializations.
*/

#include<iostream>
using namespace std;

// Default initialization prior to C++11
class Human {
  public:
    unsigned age;
    Human() : age{11} {}

    void print()
    {
        cout << "Human age " << age << "\n";
    }
};

// Default initialization on C++11
class Human1 {
  public:
    unsigned age {22};
    
    void print()
    {
        cout << "Human age " << age << "\n";
    }
};

int main(){
    Human H;
    H.print();

    Human1 H1;
    H1.print();

    return 0;    
}
// Initilizer list 

#include<iostream>
#include<vector>
using namespace std;

// Define your own initializer list constructor 
#include<initializer_list>
class A{
   vector<int> v;
    public:

   A(const initializer_list<int> &var){
         for(initializer_list<int>::iterator itr=var.begin();itr!=var.end();itr++)
         v.push_back(*itr);
   }

};
A vvar1={1,2,3};
A vvar2{1,2,3};


int main(){

// C++03 Initilizer list 
int a[3]={1,2,3};

//C++03 (check clang 3.8) // -std=c++11
vector<int> v1;
v1.push_back(11);
v1.push_back(22);
v1.push_back(33);

/* If C++03 is there than we need to add each entry like above in C++11 we can able to add like below which call class A constructor */
vector<int> v2={1,2,3}; //Call Initilizer list constructor 

}

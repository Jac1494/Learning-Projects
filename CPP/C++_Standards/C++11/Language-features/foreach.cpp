// Check with clang 3.8 without -std=c++11
// foreach
#include<iostream>
#include<vector>
using namespace std;

int main(){

   vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);

// C++ 03:
  for(vector<int>::iterator itr =v.begin(); itr!=v.end() ; ++itr)
    cout << (*itr) << " ";
    cout << "\n";

// C++ 11:

  for(auto& i:v) {
     i++;          // changes the values in v
   }

   for (int i: v) { // works on any class that has begin() and end()
     cout << i << " ";   // Readonly access
   }
}
/*
Output:-
======
1 2 3 
2 3 4
*/




/*
Set Sorted in Descending Order:-
- By default, the std::set is sorted in ascending order. However, we have 
  the option to change the sorting order by using the following syntax.

- std::set <data_type, greater<data_type>> set_name;

*/

// C++ program to demonstrate the creation of descending
// order set container
#include <iostream>
#include <set>
using namespace std;

void print(set<int, greater<int> > v)
{
    cout << "set elements : ";
	for(const int &value:v)
	cout << value << " ";
	cout << "\n";
}
void print(set<int> v)
{   
	// Method - 1
	cout << "set elements : ";
	for(const int &value:v)
	cout << value << " ";
	cout << "\n";

	// // Method - 2
	// cout << "set elements : ";
	// for(auto it=v.begin();it!=v.end();it++)
	// cout << *it << " ";
	// cout << "\n";

    // Errors:-

	// // Method - 3
	// cout << "set elements : ";
	// for ( int i=0; i<v.size(); i++)
	// 	cout << v.at(i) << " ";    
	// cout << "\n";

	// // Method - 4
	// cout << "set elements : ";
	// for (int i = 0; i < v.size(); i++)
	// 	cout << v[i] << " ";
	// cout << "\n";
	
	// 1. cout << get<0>(v) << " " ;   
}

int main()
{
	set<int, greater<int> > s1;        // Decending order

/*
Time complexity: O(N) // N is the size of the set.
Auxiliary Space: O(N)
*/    
    cout << "Set 1 :- " ;
	s1.insert(10);
	s1.insert(5);
    s1.insert(5);      
	s1.insert(12);
	s1.insert(4);
    print(s1);  // Need different print // 12 10 5 4
    
    set<int> s2(s1.begin(), s1.end()); // Ascending order

    cout << "Set 2 :- " ;
	print(s2);      // 4 5 10 12 

/*
Insertion of Elements – O(log N)
Deletion of Elements – O(log N)
*/
    s2.erase(12);

    cout << "Set 2 :- " ;
    print(s2);      // 4 5 10 

       // lower bound and upper bound for set s2
    cout << "s2.lower_bound(40) : " << *s2.lower_bound(5) << endl;  // 5
    cout << "s2.upper_bound(40) : " << *s2.upper_bound(5) << endl;  // 10

    s2.count(5) ? cout << "Present\n":cout << "Not Present\n"; // Present
    

	return 0;
}

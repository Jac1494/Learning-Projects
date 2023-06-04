/*
Multisets:-
- Multisets are a type of associative containers similar to the set, with 
  the exception that multiple elements can have the same values.

- begin() – Returns an iterator to the first element in the multiset –>  O(1)
- end() – Returns an iterator to the theoretical element that follows the last element in the multiset –> O(1)
- size() – Returns the number of elements in the multiset –> O(1)
- max_size() – Returns the maximum number of elements that the multiset can hold –> O(1)
- empty() – Returns whether the multiset is empty –> O(1)
- insert (x) – Inserts the element x in the multiset –> O(log n)
- clear () – Removes all the elements from the multiset –> O(n)
- erase(x) – Removes all the occurrences of x –> O(log n)
- Insertion of Elements- O(log N)
- Accessing Elements – O(log N)
- Deleting Elements- O(log N)

- a.erase() – Remove all instances of element from multiset having the same value
- a.erase(a.find()) – Remove only one instance of element from multiset having same value

*/

#include <iostream>
#include <set>
using namespace std;

void print(multiset<int, greater<int> > v)
{
	cout << "elements : ";
	for(const int &value:v)
		cout << value << " ";
	cout << "\n";
}
void print(multiset<int> v)
{   
	// Method - 1
	cout << "elements : ";
	for(const int &value:v)
		cout << value << " ";
	cout << "\n";

	// // Method - 2
	// cout << "multiset elements : ";
	// for(auto it=v.begin();it!=v.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// Errors:-

	// // Method - 3
	// cout << "multiset elements : ";
	// for ( int i=0; i<v.size(); i++)
	// 	cout << v.at(i) << " ";    
	// cout << "\n";

	// // Method - 4
	// cout << "multiset elements : ";
	// for (int i = 0; i < v.size(); i++)
	// 	cout << v[i] << " ";
	// cout << "\n";

	// 1. cout << get<0>(v) << " " ;   
}

int main()
{
	multiset<int, greater<int> > s1;        // Decending order

	cout << "multiset 1 " ;
	s1.insert(10);
	s1.insert(5);
	s1.insert(5);      
	s1.insert(12);
	s1.insert(4);
	print(s1);  // Need different print // 12 10 5 5 4

	multiset<int> s2(s1.begin(), s1.end()); // Ascending order

	cout << "multiset 2 " ;
	print(s2);      // 4 5 5 10 12 

	s2.erase(12);

	cout << "multiset 2 " ;
	print(s2);      // 4 5 5 10 

	// lower bound and upper bound for multiset s2
	cout << "s2.lower_bound(40) : " << *s2.lower_bound(5) << endl;  // 5
	cout << "s2.upper_bound(40) : " << *s2.upper_bound(5) << endl;  // 10

	s2.count(5) ? cout << "Present\n":cout << "Not Present\n"; // Present

	s2.erase(s2.find(5));

	cout << "multiset 2  " ;
	print(s2);      // 4 5 10 

	return 0;
}

/*
unordered_multiset:-
- the problem with unordered_set is that, it is not possible to store duplicate 
  entries in that data structure. For example if we have some value v already in 
  unordered_set, inserting v again will have no effect. 
- The internal implementation of unordered_multiset is same as that of unordered_set 
  and also uses hash table for searching, just the count value is associated with
  each value in former one. 
- Due to hashing of elements it has no particular order of storing the elements so 
  all element can come in any order but duplicate element comes together. All 
  operation on unordered_multiset takes constant time on average but can go upto 
  linear in worst case.   

*/

// C++ program to demonstrate various function of unordered_multiset
#include <bits/stdc++.h>
using namespace std;

// making typedef for short declaration
typedef unordered_multiset<int>::iterator umit;

// Utility function to print unordered_multiset
void printUset(unordered_multiset<int> ums)
{
	// begin() returns iterator to first element of set
	umit it = ums.begin();
	for (; it != ums.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	// empty initialization
	unordered_multiset<int> ums1;

	// Initialization by intializer list
	unordered_multiset<int> ums2 ({1, 3, 1, 7, 2, 3,
			4, 1, 6});

	// Initialization by assignment
	ums1 = {2, 7, 2, 5, 0, 3, 7, 5};

	// empty() function return true if set is empty otherwise false
	if (ums1.empty())
		cout << "unordered multiset 1 is empty\n";
	else
		cout << "unordered multiset 1 is not empty\n";  // true

	// size() function returns total number of elements in data structure
	cout << "The size of unordered multiset 2 is : "
		<< ums2.size() << endl;     // 9

	printUset(ums1);       // 3 0 5 5 7 7 2 2

	ums1.insert(7);

	printUset(ums1);       // 3 0 5 5 7 7 7 2 2

	int val = 3;

	// find function returns iterator to first position of val, 
	// if exist otherwise it returns iterator to end
	if (ums1.find(val) != ums1.end())
		cout << "unordered multiset 1 contains " << val << endl;  // 3
	else
		cout << "unordered multiset 1 does not contains " << val << endl;

	// count function returns total number of occurrence in set
	val = 5;
	int cnt = ums1.count(val);
	cout << val << " appears " << cnt << " times in unordered multiset 1 \n";  // 5 appers 2 times in ...

	val = 9;

	// if count return >0 value then element exist otherwise not
	if (ums1.count(val))
		cout << "unordered multiset 1 contains " << val << endl;  
	else
		cout << "unordered multiset 1 does not contains " << val << endl; // true

	val = 1;

	// equal_range returns a pair, where first is iterator to first position 
	// of val and second it iterator to last position to val
	pair<umit, umit> erange_it = ums2.equal_range(val);
	if (erange_it.first != erange_it.second)
		cout << val << " appeared atleast once in " "unoredered_multiset \n"; // 1 appered ...

	printUset(ums2); // 6 4 2 7 3 3 1 1 1

	// erase function deletes all instances of val (which is 1)
	ums2.erase(val);

	printUset(ums2); // 6 4 2 7 3 3

	// clear function deletes all entries from set
	ums1.clear();
	ums2.clear();

	if (ums1.empty())
		cout << "unordered multiset 1 is empty\n";  // true
	else
		cout << "unordered multiset 1 is not empty\n";
}

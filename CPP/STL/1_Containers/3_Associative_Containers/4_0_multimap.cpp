/*
Multimap:-
- Multimap is similar to a map with the addition that multiple elements can have the same keys. 
  Also, it is NOT required that the key-value and mapped value pair have to be unique in this case. 
- One important thing to note about multimap is that multimap keeps all the keys in sorted order always. 
- These properties of multimap make it very much useful in competitive programming.
*/

#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{
	multimap<int, int> mmap1; // empty multimap container

	// insert elements in random order
	mmap1.insert(pair<int, int>(1, 40));
	mmap1.insert(pair<int, int>(2, 30));
	mmap1.insert(pair<int, int>(3, 60));
	mmap1.insert(pair<int, int>(3, 60));    // This will also work 
	mmap1.insert(pair<int, int>(6, 50));
	mmap1.insert(pair<int, int>(6, 10));    // This too work

	// printing multimap mmap1
	multimap<int, int>::iterator itr;
	cout << "\nThe multimap mmap1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = mmap1.begin(); itr != mmap1.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}
	cout << endl;

	// adding elements randomly,
	// to check the sorted keys property
	mmap1.insert(pair<int, int>(4, 50));
	mmap1.insert(pair<int, int>(5, 10));

	// printing multimap mmap1 again

	cout << "\nThe multimap mmap1 after adding extra "
		"elements is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = mmap1.begin(); itr != mmap1.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}
	cout << endl;

	// assigning the elements from mmap1 to gquiz2
	multimap<int, int> gquiz2(mmap1.begin(), mmap1.end());

	// print all elements of the multimap gquiz2
	cout << "\nThe multimap gquiz2 after assign from "
		"mmap1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}
	cout << endl;

	// remove all elements up to
	// key with value 3 in gquiz2
	cout << "\ngquiz2 after removal of elements less than "
		"key=3 : \n";
	cout << "\tKEY\tELEMENT\n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}

	// remove all elements with key = 4
	int num;
	num = gquiz2.erase(4);
	cout << "\ngquiz2.erase(4) : ";
	cout << num << " removed \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}

	cout << endl;

	// lower bound and upper bound for multimap mmap1 key =
	// 5
	cout << "mmap1.lower_bound(5) : "
		<< "\tKEY = ";  
	cout << mmap1.lower_bound(5)->first << '\t';            // 5 
	cout << "\tELEMENT = " << mmap1.lower_bound(5)->second  // 10
		<< endl;
	cout << "mmap1.upper_bound(5) : "
		<< "\tKEY = ";  
	cout << mmap1.upper_bound(5)->first << '\t';            // 6
	cout << "\tELEMENT = " << mmap1.upper_bound(5)->second  // 50
		<< endl;


	return 0;
}

// Non-Manipulating Algorithms

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
using namespace std;

void v_print(vector<int> v,int n)
{
	for (int i=0; i<n; i++)
		cout << v[i] << " ";
    cout << "\n";
}
int main()
{
	vector<int> vect{10, 20, 5, 23 ,42 , 15};

	cout << "Vector is: ";
	v_print(vect,vect.size());

	// Sorting the Vector in Ascending order
	sort(vect.begin(), vect.end());

	cout << "Vector after sorting is: ";
	v_print(vect,vect.size());

	// Sorting the Vector in Descending order
	sort(vect.begin(),vect.end(), greater<int>());

	cout << "Vector after sorting in Descending order is: ";
    v_print(vect,vect.size());

	// Reversing the Vector (descending to ascending , ascending to descending)
	reverse(vect.begin(), vect.end());

	cout << "Vector after reversing is: ";
	v_print(vect,vect.size());

	cout << "\nMaximum element of vector is: ";
	cout << *max_element(vect.begin(), vect.end());

	cout << "\nMinimum element of vector is: ";
	cout << *min_element(vect.begin(), vect.end());

	// Starting the summation from 0
	cout << "\nThe summation of vector elements is: ";
	cout << accumulate(vect.begin(), vect.end(), 0);

    cout << "\nOccurrences of 20 in vector : ";
 
    // Counts the occurrences of 20 from 1st to last element
    cout << count(vect.begin(), vect.end(), 20);
 
    // find() returns iterator to last address i element not present
    find(vect.begin(), vect.end(),5) != vect.end()?
                         cout << "\nElement found":
                     cout << "\nElement not found";

    // Sort the array to make sure that lower_bound()
    // and upper_bound() work.
    sort(vect.begin(), vect.end());
 
    // Returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);
 
    // Returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);
 
    cout << "\nThe lower bound is at position: ";
    cout << q-vect.begin();
 
    cout << "\nThe upper bound is at position: ";
    cout << p-vect.begin();                     
 
	return 0;
}
/*
Vector is: 10 20 5 23 42 15 
Vector after sorting is: 5 10 15 20 23 42 
Vector after sorting in Descending order is: 42 23 20 15 10 5 
Vector after reversing is: 5 10 15 20 23 42 

Maximum element of vector is: 42
Minimum element of vector is: 5
The summation of vector elements is: 115
Occurrences of 20 in vector : 1
Element found
The lower bound is at position: 3
The upper bound is at position: 4
*/

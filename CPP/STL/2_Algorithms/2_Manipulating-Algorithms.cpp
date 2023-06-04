// C++ program to demonstrate working
// of erase
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void v_print(vector<int> v,int n)
{
	for (int i=0; i<n; i++)
		cout << v[i] << " ";
    cout << "\n";
}

int main()
{
	vector<int> vect{ 5, 10, 15, 20, 20, 23, 42, 45 };

	cout << "Given Vector is: ";
    v_print(vect,vect.size());

	vect.erase(find(vect.begin(),vect.end(),10));
	cout << "Vector after erasing element: ";
	v_print(vect,vect.size());

	vect.erase(unique(vect.begin(), vect.end()),vect.end());
	cout << "Vector after removing duplicates: ";
	v_print(vect,vect.size());

    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    cout << "Vector after performing next permutation: ";
    v_print(vect,vect.size());
 
    prev_permutation(vect.begin(), vect.end());
    cout << "Vector after performing prev permutation: ";
    v_print(vect,vect.size());

	return 0;
}
/*
Given Vector is: 5 10 15 20 20 23 42 45 
Vector after erasing element: 5 15 20 20 23 42 45 
Vector after removing duplicates: 5 15 20 23 42 45 
Vector after performing next permutation: 5 15 20 23 45 42 
Vector after performing prev permutation: 5 15 20 23 42 45 
*/

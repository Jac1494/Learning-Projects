/*
Array:-
- The introduction of array class from C++11 has offered a better alternative for C-style arrays. 

The advantages of array class over C-style array are :- 
1. Array classes knows its own size, whereas C-style arrays lack this property. 
  So when passing to functions, we don’t need to pass size of Array as a separate parameter.
2. With C-style array there is more risk of array being decayed into a pointer. 
  Array classes don’t decay into pointers
3. Array classes are generally more efficient, light-weight and reliable than C-style arrays.
*/

#include<iostream>
#include<array> // for array, at()
#include<tuple> // for get()
using namespace std;

// Point 1
void print(array<int,6> &ar)
{   
	// The array elements in print function using at()
	cout << "The array elements : ";
	for ( int i=0; i<6; i++)
		cout << ar.at(i) << " ";    // OR cout << ar[i] << " ";
	cout << endl;

}
int main()
{
	// Initializing the array elements
	array<int,6> ar = {1, 2, 3, 4, 5, 6};
	print(ar);   // 1 2 3 4 5 6 

	// Printing array elements using get()
	cout << "The array elements are (using get()) : ";
	cout << get<0>(ar) << " " << get<1>(ar) << " ";   // 1 2
	cout << get<2>(ar) << " " << get<3>(ar) << " ";   // 3 4
	cout << get<4>(ar) << " " << get<5>(ar) << " ";   // 5 6
	cout << endl;

	cout << "First element of array is : " << ar.front() << endl; // 1 

	cout << "Last element of array is : "  << ar.back() << endl;  // 6

	cout << "The number of array elements is : " << ar.size() << endl;  // 6

	cout << "Maximum elements array can hold is : " << ar.max_size() << endl; // 6

	// Check it is empty 
	ar.empty()? cout << "Array empty":cout << "Array not empty"; // Array not empty
	cout << endl;

	// swap arrays
	array<int,6> ar1 = {7, 8, 9, 10, 11, 12};
	cout << "=========> Swap Function <=========" << endl;
	print(ar);     // 1 2 3 4 5 6
	print(ar1);    // 7 8 9 10 11 12 
	ar.swap(ar1);
	print(ar);     // 7 8 9 10 11 12 
	print(ar1);    // 1 2 3 4 5 6
	cout << "===================================" << endl;

	// Filling array with 0
	ar.fill(0);
	print(ar);   // 0 0 0 0 0 0 

	return 0;
}

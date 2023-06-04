/*
Vector:-
- Vectors are the same as dynamic arrays with the ability to resize itself automatically 
  when an element is inserted or deleted, with their storage being handled automatically by the container. 
- Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. 
- In vectors, data is inserted at the end. Inserting at the end takes differential time, 
  as sometimes the array may need to be extended. Removing the last element takes only constant time because no resizing happens. 
- Inserting and erasing at the beginning or in the middle is linear in time.
- It is support random access for insertion and deletions.

The time complexity for doing various operations on vectors is:-

1. Random access – constant O(1)
2. Insertion or removal of elements at the end – constant O(1)
3. Insertion or removal of elements – linear in the distance to the end of the vector O(N)
4. Knowing the size – constant O(1)
5. Resizing the vector- Linear O(N)

*/

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v)
{   
	// Method - 1
	cout << "Vector elements : ";
	for ( int i=0; i<v.size(); i++)
		cout << v.at(i) << " ";    
	cout << "\n";

	// // Method - 2
	// cout << "Vector elements : ";
	// for(const int &value:v)
	// cout << value << " ";
	// cout << "\n";

	// // Method - 3
	// cout << "Vector elements : ";
	// for(auto it=v.begin();it!=v.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// // Method - 4
	// cout << "Vector elements : ";
	// for (int i = 0; i < v.size(); i++)
	// 	cout << v[i] << " ";
	// cout << "\n";

	// Errors
	// 1. cout << get<0>(v) << " " ;   
}

int main()
{
	// syntax for vector
	vector<int> v1={11,22};
	vector<int> v2;

	// 1. Added value using push_back
	v2.push_back(33);
	v2.push_back(44);
	print(v1);      // 11 22
	print(v2);      // 33 44

	// push_front is not available in vector 
	// 2. But lets push value from front
	v1.insert(v1.begin(),1);
	v1.insert(v1.begin(),2);
	print(v1);      //      2 1 11 22  

	// 3. Insert value to perticular index
	int index=2;
	v1.insert(v1.begin()+ index++,3);
	v1.insert(v1.begin()+ index++,4);
	print(v1);      //      2 1 3 4 11 22  

	// 4. Modify value to perticular index
	index=0;
	v1[index++]=1;
	v1[index++]=2;
	print(v1);      //      1 2 3 4 11 22  

	cout << "Size : " << v1.size();                 // 6
	cout << "\nCapacity : " << v1.capacity();       // 8
	cout << "\nMax_Size : " << v1.max_size();       // 2305843009213693951

	// resizes the vector size to 4
	v1.resize(4);       

	// prints the vector size after resize()
	cout << "\nSize : " << v1.size();       // 4

	// checks if the vector is empty or not
	if (v1.empty() == false)
		cout << "\nVector is not empty\n";     //  Vector is not empty
	else
		cout << "\nVector is empty\n";

	// Shrinks the vector
	v1.shrink_to_fit();     // Reduces the capacity of the container to fit its size 
				// and destroys all elements beyond the capacity.
	print(v1);

	cout << "\nReference operator [g] : v1[2] = " << v1[2]; // 3

	cout << "\nfront() : v1.front() = " << v1.front();   // 1

	cout << "\nback() : v1.back() = " << v1.back();     // 4

	// pointer to the first element
	int* pos = v1.data();
	cout << "\nThe first element is " << *pos;         // 1 

	// Swaps v1 and v2
	cout <<"\n";
	v1.swap(v2);
	print(v1);  // 33 44
	print(v2);  // 1 2 3 4 

	// fill the vector with 10 five times
	v1.assign(5, 5);
	print(v1);  // 5 5 5 5 5

	int n = v1.size();
	cout << "\nThe last element is: " << v1[n - 1]; //5

	// removes last element
	v1.pop_back();  

	// removes the first element
	v1.erase(v1.begin());

	cout << "\nThe first element is: " << v1[0];    // 5

	// inserts at the beginning
	v1.emplace(v1.begin(), 4);
	cout << "\nThe first element is: " << v1[0];    //  4

	// Inserts 20 at the end
	v1.emplace_back(20);
	n = v1.size();
	cout << "\nThe last element is: " << v1[n - 1]; // 20

	cout << "\nOutput of cbegin and cend: ";
	for (auto i = v1.cbegin(); i != v1.cend(); ++i)     // Returns a constant iterator pointer
		cout << *i << " ";          // 4 5 5 5 20

	cout << "\nOutput of rbegin and rend: ";
	for (auto ir = v1.rbegin(); ir != v1.rend(); ++ir) // Returns a constant reverse iterator pointer
		cout << *ir << " ";         // 20 5 5 5 4

	cout << "\nOutput of crbegin and crend : ";
	for (auto ir = v1.crbegin(); ir != v1.crend(); ++ir)
		cout << *ir << " ";         // 20 5 5 5 4

	// erases the vector
	v1.clear();
	cout << "\nVector size after erase(): " << v1.size();   // 0

	cout <<"\n";
	print(v1);  // Nothing will print
	print(v2);  // 1 2 3 4

	return 0;
}

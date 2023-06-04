/*
Forward List:-
- Forward list in STL implements singly linked list. Introduced from C++11, 
  forward list are more useful than other containers in insertion, removal, 
  and moving operations (like sort) and allow time constant insertion and removal of elements. 
- It differs from the list by the fact that the forward list keeps track of 
  the location of only the next element while the list keeps track of both 
  the next and previous elements, thus increasing the storage space required to store each element. 
- The drawback of a forward list is that it cannot be iterated backward and 
  its individual elements cannot be accessed directly. 
- Forward List is preferred over the list when only forward traversal is required 
  (same as the singly linked list is preferred over doubly linked list) as 
  we can save space. Some example cases are, chaining in hashing, adjacency list representation of the graph, etc.  
*/

#include <forward_list>
#include <iostream>
using namespace std;

void print(forward_list<int> &f)
{   
	// Method - 1
	cout << "Forward list elements : ";	
	for(const int &value:f)
		cout << value << " ";
	cout << "\n";

	// Method - 2
	// cout << "Forward list elements : ";
	// for(auto it=f.begin();it!=f.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// Errors
	// Reason for below error is can't able to access direct element
	// 1. cout << get<0>(v) << " " ;   
	// 2. cout << v.at(i) << " ";     
	// 3. cout << v[i] << " ";
}

int main()
{
	// Declaring forward list
	forward_list<int> flist1;
	forward_list<int> flist2;
	forward_list<int> flist3;

	// Assigning values using assign()
	flist1.assign({ 1, 2, 3 });
	print(flist1);      // 1 2 3

	// Assigning repeating values using assign()
	// 5 elements with value 10
	flist2.assign(5, 10);
	print(flist2);      // 10 10 10 10 10

	//Assigning values of list 1 to list 3
	flist3.assign(flist1.begin(), flist1.end());
	print(flist3);      // 1 2 3
			    //flist3.assign(flist1.begin()+1, flist1.end()); // Error

	/*
	   push_front():- 
	   - It is used to insert the element at the first position on forward list. 
	   - The value from this function is copied to the space before first element 
	   in the container. The size of forward list increases by 1.

	   emplace_front():- 
	   - This function is similar to the previous function but in this no copying 
	   operation occurs, the element is created directly at the memory before 
	   the first element of the forward list.
	   */

	// Inserting value using push_front()
	flist1.push_front(60);
	print(flist1);      // 60 1 2 3

	// Inserting value using emplace_front()
	flist1.emplace_front(70);
	print(flist1);      // 70 60 1 2 3

	// Deleting first value using pop_front()
	flist1.pop_front(); // Pops 70 
	print(flist1);      // 60 1 2 3

	// Declaring a forward list iterator
	forward_list<int>::iterator ptr;

	// Inserting value using insert_after() 
	ptr = flist1.insert_after(flist1.begin(), { 11, 22, 33 });	// starts insertion from second position
	print(flist1);      //  60 11 22 33 1 2 3

	// Inserting value using emplace_after()
	ptr = flist1.emplace_after(ptr, 55);		// inserts 2 after ptr
	print(flist1);      //  60 11 22 33 55 1 2 3

	// Deleting value using erase.after Deleted 2
	ptr = flist1.erase_after(ptr);  	// after ptr (ptr is at value 1)
	print(flist1);      //  60 11 22 33 55 2 3

	//ptr= flist1.erase_after(flist1.begin()+2, flist1.end());  // Index give error in forwardlist
	ptr= flist1.erase_after(ptr, flist1.end()); // ptr at value 2
	print(flist1);      //  60 11 22 33 55 2

	// Shifting elements from first to second
	// forward list after 1st position
	flist1.splice_after(flist1.begin(), flist2);
	print(flist1);      //  60 10 10 10 10 10 11 22 33 55 2 

	// Removing element using remove()
	// Removes all occurrences of 10
	flist1.remove(10);
	print(flist1);      //  60 11 22 33 55 2  

	// Removing according to condition. Removes
	// elements greater than 25 and less then 10. 
	flist1.remove_if([](int x) { return x > 25 | x < 10 ; });
	print(flist1);      //  11 22 

	flist1.clear();    // Forward List becomes empty
	print(flist1);      //  No value 

	return 0;
}

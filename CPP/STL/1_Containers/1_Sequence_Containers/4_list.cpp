/*
List:-
- Lists are sequence containers that allow non-contiguous memory allocation. 
  As compared to vector, the list has slow traversal, but once a position has 
  been found, insertion and deletion are quick. Normally, when we say a List, 
  we talk about a doubly linked list.
- List also don't support random access and subscript operator []
*/

#include <list>
#include <iostream>
using namespace std;

void print(list<int> &l)
{   
	// Method - 1
	cout << "Forward list elements : ";
	for(const int &value:l)
		cout << value << " ";
	cout << "\n";

	// // Method - 2
	// cout << "Forward list elements : ";
	// for(auto it=l.begin();it!=l.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// Errors
	// Reason for below error is can't able to access direct element
	// 1. cout << get<0>(l) << " " ;   
	// 2. cout << l.at(0) << " ";     
	// 3. cout << l[0] << " ";
}

int main()
{
	// Declaring forward list
	list<int> list1;
	list<int> list2;
	list<int> list3;

	// Assigning values using assign()
	list1.assign({ 1, 2, 3 });
	print(list1);      // 1 2 3

	// Assigning repeating values using assign()
	// 5 elements with value 10
	list2.assign(5, 11);
	print(list2);      // 11 11 11 11 11

	//Assigning values of list 1 to list 3
	list3.assign(list1.begin(), list1.end());
	print(list3);      // 1 2 3
			   //list3.assign(list1.begin()+1, list1.end()); // Error

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
	list1.push_front(60);
	print(list1);      // 60 1 2 3

	// Inserting value using emplace_front()
	list1.emplace_front(70);
	print(list1);      // 70 60 1 2 3

	// Deleting first value using pop_front()
	list1.pop_front(); // Pops 70 
	print(list1);      // 60 1 2 3

	// Declaring a forward list iterator
	list<int>::iterator ptr;

	// Below all methods are give error for list. Not any after method will work. But work only default name methods

	// ptr = dq1.insert_after(dq1.begin(), { 11, 22, 33 });	// starts insertion from second position
	// ptr = dq1.emplace_after(ptr, 55);		// inserts 2 after ptr
	// ptr = dq1.erase_after(ptr);  	// after ptr (ptr is at value 1)
	// ptr= dq1.erase_after(ptr, dq1.end()); // ptr at value 2
	// dq1.splice_after(dq1.begin(), dq2);

	ptr = list1.insert(list1.begin(), { 11, 22, 33 });	
	print(list1);      // 11 22 33 60 1 2 3 

	ptr = list1.emplace(ptr, 55);		// inserts 2 after ptr
	print(list1);      // 55 11 22 33 60 1 2 3 

	// ptr = ptr + 1;  // Error
	// --ptr;          // Works because it is double linked list internally
	++ptr;          // ptr is at 11
	ptr = list1.erase(ptr);  	
	print(list1);   // 55 22 33 60 1 2 3

	ptr= list1.erase(ptr, list1.end()); // ptr at value 2
	print(list1);   // 55 

	list1.splice(list1.begin(), list2);
	print(list1);   // 11 11 11 11 11 55 

	// Removing element using remove()
	// Removes all occurrences of 55
	list1.remove(11);
	print(list1);      //  55

	list1={10,20,30,40};    // Override list
	print(list1);      //  10 20 30 40

	// Removing according to condition. Removes
	// elements greater than 25 and less then 10. 
	list1.remove_if([](int x) { return x > 25 | x < 10 ; });
	print(list1);      //  10 20 

	list1.clear();    // Forward List becomes empty
	print(list1);      //  No value 

	return 0;
}

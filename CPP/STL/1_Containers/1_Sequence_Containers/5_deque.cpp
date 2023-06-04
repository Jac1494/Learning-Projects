/*
Deque:-
- Double-ended queues are sequence containers with the feature of expansion and 
  contraction on both ends. 
- They are similar to vectors, but are more efficient in case of insertion and deletion 
  of elements. Unlike vectors, contiguous storage allocation may not be guaranteed. 
- Double Ended Queues are basically an implementation of the data structure double-ended queue. 
  A queue data structure allows insertion only at the end and deletion from the front. 
- This is like a queue in real life, wherein people are removed from the front and added at the back. 
- Double-ended queues are a special case of queues where insertion and deletion operations 
  are possible at both the ends. The functions for deque are same as vector, with an addition 
  of push and pop operations for both front and back. It is also support random data access. 

The time complexities for doing various operations on deques are-

1. Accessing Elements- O(1)
2. Insertion or removal of elements- O(N)
3. Insertion or removal of elements at start or end- O(1)
*/

#include <deque>
#include <iostream>
using namespace std;

void print(deque<int> &dq)
{   
	// Method - 1
	cout << "deque elements : ";
	for(const int &value:dq)
		cout << value << " ";
	cout << "\n";

	// // Method - 2
	// cout << "deque elements : ";
	// for(auto it=dq.begin();it!=dq.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// // Method - 3
	// cout << "deque elements : ";
	// for (int i = 0; i < dq.size(); i++)
	// 	cout << dq[i] << " ";
	// cout << "\n";

	// Errors
	// Reason for below error is can't able to access direct element
	// 1. cout << get<0>(l) << " " ;   
	// 2. cout << l.at(0) << " ";     
}

int main()
{
	// Declaring forward dq
	deque<int> dq1;
	deque<int> dq2;
	deque<int> dq3;

	// Assigning values using assign()
	dq1.assign({ 1, 2, 3 });
	print(dq1);      // 1 2 3

	// Assigning repeating values using assign()
	// 5 elements with value 10
	dq2.assign(5, 11);
	print(dq2);      // 11 11 11 11 11

	//Assigning values of dq 1 to dq 3
	dq3.assign(dq1.begin(), dq1.end());
	print(dq3);      // 1 2 3
			 //dq3.assign(dq1.begin()+1, dq1.end()); // Error

	/*
	   push_front():- 
	   - It is used to insert the element at the first position on forward dq. 
	   - The value from this function is copied to the space before first element 
	   in the container. The size of forward dq increases by 1.
	   emplace_front():- 
	   - This function is similar to the previous function but in this no copying 
	   operation occurs, the element is created directly at the memory before 
	   the first element of the forward dq.
	   */

	// Inserting value using push_front()
	dq1.push_front(60);
	print(dq1);      // 60 1 2 3

	// Inserting value using emplace_front()
	dq1.emplace_front(70);
	print(dq1);      // 70 60 1 2 3

	// Deleting first value using pop_front()
	dq1.pop_front(); // Pops 70 
	print(dq1);      // 60 1 2 3

	// Declaring a forward dq iterator
	deque<int>::iterator ptr;

	// Below all methods are give error for deque. Not any after method will work. 
	// But work only default name methods works like insert,emplace etc.

	// ptr = dq1.insert_after(dq1.begin(), { 11, 22, 33 });	// starts insertion from second position
	// ptr = dq1.emplace_after(ptr, 55);		// inserts 2 after ptr
	// ptr = dq1.erase_after(ptr);  	// after ptr (ptr is at value 1)
	// ptr= dq1.erase_after(ptr, dq1.end()); // ptr at value 2
	// dq1.splice_after(dq1.begin(), dq2);

	ptr = dq1.insert(dq1.begin(), { 11, 22, 33 });	
	print(dq1);      // 11 22 33 60 1 2 3 

	ptr = dq1.emplace(ptr, 55);		// inserts 2 after ptr
	print(dq1);      // 55 11 22 33 60 1 2 3 

	// ptr = ptr + 1;  // Error
	// --ptr;          // Works because it is double linked dq internally
	++ptr;          // ptr is at 11
	ptr = dq1.erase(ptr);  	
	print(dq1);   // 55 22 33 60 1 2 3

	ptr= dq1.erase(ptr, dq1.end()); // ptr at value 2
	print(dq1);   // 55 

	dq1[0]=99;
	print(dq1);      //  99

	dq1={10,20,30,40};    // Override dq
	print(dq1);      //  10 20 30 40

	dq1.clear();    // Forward dq becomes empty
	print(dq1);      //  No value 

	return 0;
}

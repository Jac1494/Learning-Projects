/*
Priority Queue:-
- A C++ priority queue is a type of container adapter, specifically designed such 
 that the first element of the queue is either the greatest or the smallest of all elements 
 in the queue, and elements are in non-increasing or non-decreasing order 
 (hence we can see that each element of the queue has a priority {fixed order}).

- In C++ STL, the top element is always the greatest by default. We can also change 
  it to the smallest element at the top. Priority queues are built on the top of 
  the max heap and use an array or vector as an internal structure. 
  In simple terms, STL Priority Queue is the implementation of Heap Data Structure.

Syntax:-
    std::priority_queue<int> pq;

Methods				->  Time Complexity -> Auxiliary Space
====================================================================== 
priority_queue::empty()		-> O(1) -> O(1)

priority_queue::size() 		-> O(1) -> O(1)

priority_queue::top() 		-> O(1) -> O(1)

priority_queue::push() 		-> O(logN) -> O(1)

priority_queue::pop() 		-> O(logN) -> O(1)

priority_queue::swap() 		-> O(1) -> O(N)

priority_queue::emplace() 	-> O(logN) -> O(1)

priority_queue value_type 	-> O(1) -> O(1)

*/

// C++ program to demonstrate the use of priority_queue
#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int> pq)
{   
	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
    cout << "\n";
}    
int main()
{
	int arr[6] = { 10, 2, 4, 8, 6, 9 };

	// defining priority queue
	priority_queue<int> pq;

	// printing array
	cout << "Array: ";  
	for (auto i : arr) {
		cout << i << ' ';   // 10 2 4 8 6 9
	}
	cout << endl;
	// pushing array sequentially one by one
	for (int i = 0; i < 6; i++) {
		pq.push(arr[i]);
	}

    print(pq);  // 10 9 8 6 4 2 

    // used for telling the top element  in priority queue
    cout << "\npq.top() : " << pq.top();    // 10
 
    // used for popping the element from a priority queue
    cout << "\npq.pop() : ";
    pq.pop();
    cout << "\n";
    print(pq);  // 9 8 6 4 2 

    pq.empty() ? cout << "\nEmpty or true\n":cout << "\nContains element or False\n";   // contain element

    cout << "Size of the priority queue: " << pq.size();    // 5

/*
Emplace():-> This function is used to insert a new element into the priority queue 
container, the new element is added to the priority queue according to its priority. 
It is similar to push operation. The difference is that emplace() operation saves unnecessary copy of the object.
*/
    pq.emplace(10);
    priority_queue<int> pq2;
 
    pq2.push(3);
    pq2.push(5);
    pq2.push(7);
    pq2.push(9);
 
    cout << "\n\nBefore swapping:-" << "\n";
    print(pq);      // 10 9 8 6 4 2
    print(pq2);     // 9 7 5 3
 
    // using swap() function to swap elements of priority
    // queues
    pq.swap(pq2);  
 
    cout << endl << "After swapping:- " << "\n";    
    print(pq);      // 9 7 5 3
    print(pq2);     // 10 9 8 6 4 2

	return 0;
}

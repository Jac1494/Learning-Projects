/*
Queues:-
- Queues are a type of container adaptors that operate in a first in first out (FIFO) type 
  of arrangement. Elements are inserted at the back (end) and are deleted from the front. 
- Queues use an encapsulated object of deque or list (sequential container class) as 
  its underlying container, providing a specific set of member functions to access its elements.

queue::empty()	O(1)
queue::size()	O(1)
queue::emplace()	O(1)
queue::front()	O(1)
queue::back()	O(1)
queue::push(g) 	O(1)
queue::pop() 	O(1)

*/

#include <queue>
#include <iostream>
using namespace std;

void print(queue<int> &gq)
{   
	queue<int> g = gq;
	while (!g.empty()) {
		cout << " " << g.front();
		g.pop();
	}
	cout << "\n";    
	// Below all methods are give error for queue

	// // Method - 1
	// cout << "queue elements : ";
	// for(const int &value: dq)
	// 	cout << value << " ";
	// cout << "\n";

	// // Method - 2
	// cout << "queue elements : ";
	// for(auto it=dq.begin();it!=dq.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// // Method - 3
	// cout << "queue elements : ";
	// for (int i = 0; i < dq.size(); i++)
	// 	cout << dq[i] << " ";
	// cout << "\n";

	// Reason for below error is can't able to access direct element
	// 1. cout << get<0>(l) << " " ;   
	// 2. cout << l.at(0) << " ";     
}

int main()
{
	// Declaring forward dq
	queue<int> dq1;
	dq1.push(10);
	dq1.push(20);
	dq1.push(30);

	queue<int> dq2;
	dq2.push(4);
	dq2.push(5);

	cout << "The queue dq1 is : ";
	print(dq1); // 10 20 30 
	cout << "The queue dq2 is : ";
	print(dq2); // 4 5 6 

	cout << "\ndq1.size() : " << dq1.size();        // 3
	cout << "\ndq1.front() : " << dq1.front();      // 10
	cout << "\ndq1.back() : " << dq1.back();        // 30

	cout << "\ndq1.pop() : ";
	dq1.pop();
	cout << "\n";

	// queue<int>::iterator ptr;  // Error 
	dq1.empty() ? cout << "\nEmpty\n":cout << "\nNon-Empty\n";  // Non-Empty


	cout << "The queue dq1 is : ";
	print(dq1);     // 20 30
	cout << "The queue dq2 is : ";
	print(dq2); // 20 30

	dq1.swap(dq2);

	cout << "The queue dq1 is : ";
	print(dq1); // 4 5 
	cout << "The queue dq2 is : ";
	print(dq2); // 20 30

	return 0;
}

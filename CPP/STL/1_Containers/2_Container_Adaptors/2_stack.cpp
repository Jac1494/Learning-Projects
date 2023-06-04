/*
Stack :-
- Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, 
 where a new element is added at one end (top) and an element is removed from that end only.  
- Stack uses an encapsulated object of either vector or deque (by default) or list 
  (sequential container class) as its underlying container, providing a specific set 
  of member functions to access its elements. 

- If there is confusion in remembering the basic difference between stack and queue, 
  then just have a real life example for this differentiation, for stack, stacking of books 
  we can take the top book easily and for queue remember when you have to stand in queue 
  front of ATM for taking out the cash, then first person near to ATM has the first chance 
  to take out the money from ATM. So, queue is the FIFO (First In First Out) type working.

*/

#include <stack>
#include <iostream>
using namespace std;

void print(stack<int> &st)
{   
	while (!st.empty()) {
		cout << st.top() <<" ";
		st.pop();
	}
	cout << "\n";    

	// Below all methods are give error for stack

	// cout << "\n";    

	// // Method - 1
	// cout << "stack elements : ";
	// for(const int &value: dq)
	// 	cout << value << " ";
	// cout << "\n";

	// // Method - 2
	// cout << "stack elements : ";
	// for(auto it=dq.begin();it!=dq.end();it++)
	// cout << *it << " ";
	// cout << "\n";

	// // Method - 3
	// cout << "stack elements : ";
	// for (int i = 0; i < dq.size(); i++)
	// 	cout << dq[i] << " ";
	// cout << "\n";

	// Reason for below error is can't able to access direct element
	// 1. cout << get<0>(l) << " " ;   
	// 2. cout << l.at(0) << " ";     
}

int main() {
	// stack<int> S{11}; or stack<int> S={11}; // ERROR
	// It is only support push and pop function
	stack<int> stack;
	stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
	stack.push(22);
	stack.push(24);
	stack.push(25);
	int num=0;
	stack.push(num);
	stack.pop();
	stack.pop();
	stack.pop();

	print(stack);
	return 0;
}

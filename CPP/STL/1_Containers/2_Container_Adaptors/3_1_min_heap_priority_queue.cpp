/*
How to create a min heap for the priority queue?
As we saw earlier, a priority queue is implemented as max heap by default in C++ but, it also provides us an option to change it to min heap by passing another parameter while creating a priority queue.

Syntax:-
    priority_queue <int, vector<int>, greater<int>> gq;
*/

// C++ program to demonstrate
// min heap for priority queue
#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int> > gq)
{
	priority_queue<int, vector<int>, greater<int> > g = gq;
	while (!g.empty()) {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// Driver Code
int main()
{
	int arr[6] = { 10, 2, 4, 8, 6, 9 };
	priority_queue<int, vector<int>, greater<int> > gquiz(
		arr, arr + 6);	// Here caculation is done for array is 1 not 0 (arr + 5)

	cout << "Array: ";
	showArray(arr, 6);	// 10 2 4 8 6 9 

	cout << "Priority Queue : ";
	showpq(gquiz);		// 2 4 6 8 9 10

	return 0;
}

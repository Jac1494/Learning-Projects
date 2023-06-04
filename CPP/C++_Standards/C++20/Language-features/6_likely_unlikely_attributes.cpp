/*
[[likely]] and [[unlikely]] attributes:-
- Provides a hint to the optimizer that the labelled statement has a high probability 
  of being executed.
*/

#include <iostream>
using namespace std;

// Driver Code
int main()
{
	int n = 40;
	[[likely]] if (n < 100) { cout << n * 2 << "\n"; }  // 80

	[[unlikely]] while (n > 100)
	{
		n = n / 2;
		cout << n << endl;      
	}

	n = 500;
	[[likely]] if (n < 100) { cout << n * 2; }

	[[unlikely]] while (n > 100)
	{
		n = n / 2;
		cout << n << endl;      // 250 // 125 // 62
	}
	return 0;
}

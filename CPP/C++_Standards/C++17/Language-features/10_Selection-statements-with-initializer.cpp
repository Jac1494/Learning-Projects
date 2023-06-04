/*
Selection statements with initializer:-
- New versions of the if and switch statements which simplify common code 
  patterns and help users keep scopes tight.
*/

#include <iostream>
using namespace std;

int main()
{
	int arr1[]={1,2,3,4,5};

	cout <<  "=== if and else ====\n";
	for(int i=0;i<5;i++)
	{
		if(int val=arr1[i]; val % 2 ==0)
		{
			cout << arr1[i] << " is even \n";
		}
		else
		{
			cout << arr1[i] << " is odd \n";
		}
	}

	cout <<  "=== switch ====\n";
	int arr2[]={11,22,33,44,55};
	for(int i=0;i<5;i++)
	{
		switch(int val=arr2[i]; val=(val % 2 ==0))
		{
			case 0: cout << arr2[i] << " is even \n";
				break;

			case 1: cout << arr2[i] << " is odd \n";
				break;
		}
	}
	return 0;
}
/*
=== if and else ====
1 is odd 
2 is even 
3 is odd 
4 is even 
5 is odd 
=== switch ====
11 is even 
22 is odd 
33 is even 
44 is odd 
55 is even 
*/

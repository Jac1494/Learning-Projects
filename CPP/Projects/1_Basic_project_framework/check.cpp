#include<iostream>
#include "test.cpp"
using namespace std;

int main()
{
	A obj;
	obj.setValue(11);
	cout << "Value => " << obj.getValue() << "\n";
	return 0;
}

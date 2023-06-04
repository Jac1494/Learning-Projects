#include<iostream>
using namespace std;

/*
Friend Function:-
- It is non member function use to excess private data of perticular class.
- This pointer is not there in friend function.
*/
class A {

	int var;
	public:
	A(int x) {
		var=x; 
	}
	friend void print(A&);
};

void print(A &ob)
{
	cout << " var - " << ob.var << "\n";  // 99
}

int main(){

	A a(99);
	print(a);

}

/*
Member function:-
1. It will access class data without object.
2. It is part of class.
3. It is invoked only with object.
4. Scope is limited to classs.
5. It is use to access/update/assign data of same class.

Friend function:-
1. It will access class data only with the object.
2. It is not part of class.
3. It is invoked directly. And object is passed as argument.
4. A function as friend declared an any no of class.
5. It is use to access private data of class.
*/
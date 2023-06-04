/* 
Friend class:-
- accessing private member of class A in to the class B
*/

#include<iostream>
using namespace std;

class A {

	int var;
	public:
	A(int x) {
		var=x; 
	}
	friend class B;
};

class B {

	public:
		void print(A &ob)
		{
			cout << " var - " << ob.var << "\n";   // 99
		}

};
int main(){

	A a(99);
	B b;
	b.print(a);

}

/*
   - Custom deleter
   */
#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
	int length;
	int breadth;

	public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area()
	{
		return length * breadth;
	}
};

void deleter(Rectangle * o) {
	printf("deleter: ");
	if(o) {
		printf("%d\n", o->area()); // deleter
		delete o;
	} else {
		printf("[null]\n");
	}
	fflush(stdout);
}

int main()
{

	/*
	   - We can pass argument deleter function like below, this can't work
	   for make_share_ptr. We can to pass function pointer or functor 
	   */
	shared_ptr<Rectangle> P1(new Rectangle(10, 5),deleter);
	cout << P1->area() << endl;  // 50
	cout << P1.use_count() << endl; // 1

	P1.reset();
	cout << P1.use_count() << endl; // 0

	return 0;
}

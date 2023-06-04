/*
3. weak_ptr 
- It’s much more similar to shared_ptr except it’ll not maintain a Reference 
  Counter. In this case, a pointer will not have a stronghold on the object. 
  The reason is if suppose pointers are holding the object and requesting for 
  other objects then they may form a Deadlock. 
- we can able to create weak pointer from shared_ptr or weak_ptr it self.  
- It will not increase use_count , So we can work and remove that.
*/

#include <iostream>
using namespace std;
#include <memory>

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

int main()
{
	shared_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl;  // 50

	auto P2 = weak_ptr<Rectangle>(P1);
	cout << P1.use_count() << endl;  // 1
	/*
	   - We get use_count for weak_ptr but we can't get value of that.
	   For that we need use lock method which return's shared pointer ,
	   and we can able to get value for weak pointer
	   */
	// cout << P2->area() << endl;  // Error
	auto sp=P2.lock();
	cout << sp->area() << endl;  // 50

	cout << P1.use_count() << endl;  // 2
	cout << P1->area() << endl;  // 50

	return 0;
}

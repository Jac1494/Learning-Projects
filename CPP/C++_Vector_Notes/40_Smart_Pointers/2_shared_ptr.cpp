/*
2. shared_ptr
- By using shared_ptr more than one pointer can point to this one object 
  at a time and it’ll maintain a Reference Counter using use_count() method. 
- Once use_count reach zero , it will deleted automatically.  

Note:-
- Check https://github.com/AnthonyCalandra/modern-cpp-features#stdmake_shared
*/
#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

	public:
	Rectangle(){}
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

	shared_ptr<Rectangle> P1(new Rectangle(10, 5)); // Syntax -1
	cout << P1->area() << endl;  // 50

	auto P2= make_shared<Rectangle>();     // Syntax -2
	P2 = P1;

	// This'll print 50
	cout << P2->area() << endl;  // 50 

	// This'll now not give an error,
	cout << P1->area() << endl;  // 50

	// This'll also print 50 now
	// This'll print 2 as Reference Counter is 2
	cout << P1.use_count() << endl;

	P2 = std::move(P1);
	cout << P1.use_count() << endl;  // 0
	return 0;
}

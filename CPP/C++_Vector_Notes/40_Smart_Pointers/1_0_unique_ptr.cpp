/*
1. unique_ptr
- unique_ptr stores one pointer only. We can assign a different object by 
  removing the current object from the pointer. Notice the code below. First, 
  the unique_pointer is pointing to P1. But, then we remove P1 and assign P2 
  so the pointer now points to P2.
*/

#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

	public:
	Rectangle(){}
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}

	int area(){
		return length * breadth;
	}
};

/*
   - If we pass normal unique pointer then internally it will call
   copy constructor so, it will give error because it can't more then 
   1 copy. 
   - We need pass reference , so it will work.  
   */
void print_area(unique_ptr<Rectangle> &P2){

	cout << P2->area() << endl;  // 50
}
int main(){

	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl; // This'll print 50

	// syntax 1 :- unique_ptr<Rectangle> P2(P1);
	unique_ptr<Rectangle> P2;
	P2 = std::move(P1);
	cout << P2->area() << endl;  // 50

	// syntax 2 :- std::make_unique<Rectangle>();  (C++17)
	auto P3 = std::make_unique<Rectangle>();
	// P3=P2;  // Error
	P3 = std::move(P1);
	print_area(P2);

	return 0;
}

/*
std::span:-

- Provides a lightweight view over a contiguous sequence of objects. 
  A span provides a safe way to iterate over and index into objects 
  that are arranged back-to-back in memory. Such as objects stored in a built-in array, std::array, or std::vector.

- If you typically access a sequence of back-to-back objects using 
  a pointer and an index, a span is a safer, lightweight alternative.

- The size of a span can be set at compile time by specifying it as a 
  template argument, or at runtime by specifying dynamic_extent.

- A span is a view (i.e. non-owning) of a container providing bounds-checked 
 access to a contiguous group of elements. Since views do not own their elements 
 they are cheap to construct and copy -- a simplified way to think about views 
 is they are holding references to their data. As opposed to maintaining 
 a pointer/iterator and length field, a span wraps both of those up in a single object.

- Spans can be dynamically-sized or fixed-sized (known as their extent). 
  Fixed-sized spans benefit from bounds-checking.

- Span doesn't propogate const so to construct a read-only span use std::span<const T>.

- As a side note, don’t confuse C++17 std::string_view with the std::span introduced 
  by C++20. While both are non-owning views, std::string_view is a read-only view.
  You can, obviously, create a modifiable span or subspan from a std::string or from
  a char pointer and a buffer size pair. 

*/

#include <iostream>
#include <span>
#include <vector>

// Dynamically-Sized Spans 
void print_ints(std::span<const int> ints) {
	for (const auto n : ints) {
		std::cout << n << " ";
	}
	std::cout << "\n";
}

// Example: a statically-sized span will fail to compile for containers 
// that don't match the extent of the span.

void print_three_ints(std::span<const int, 3> ints) {
	for (const auto n : ints) {
		std::cout << n << " ";
	}
	std::cout << "\n";
}


int main() {

	// Dynamically-Sized Spans 
	print_ints(std::vector{ 1, 2, 3 });                 // 1 2 3
	print_ints(std::array<int, 5>{ 1, 2, 3, 4, 5 });    // 1 2 3 4 5

	int a[10] = { 0 };
	print_ints(a);      // 0 0 0 0 0 0 0 0 0 0
        //=============================================

        // statically-sized span 
        // print_three_ints(std::vector{ 1, 2, 3 }); // ERROR
        // print_three_ints(std::array<int, 5>{ 1, 2, 3, 4, 5 }); // ERROR
        //int a[10] = { 0 };
        //print_three_ints(a); // ERROR

	std::array<int, 3> b = { 1, 2, 3 };
	print_three_ints(b); // OK          // 1 2 3

	// You can construct a span manually if required:
	std::vector c{ 1, 2, 3 };
	print_three_ints(std::span<const int, 3>{ c.data(), 3 }); // OK: set pointer and length field.      // 1 2 3
	print_three_ints(std::span<const int, 3>{ c.cbegin(), c.cend() }); // OK: use iterator pairs.       // 1 2 3

	//=============================================

	// Create and print a subspan from the above s1 span
	// without the first and last elements:
	int arr[]{44, 45, -15, 89, 6, 66};
	std::cout << "Original data: ";
	print_ints(arr);       // 44 45 -15 89 6 66

	// Create a span from a C-style array
	std::span s1{arr, std::size(a)};
	std::span s2{s1.subspan(1, s1.size() - 2)};
	std::cout << "Subspan/subview from the original data without the first and last elements: ";
	print_ints(s2);     // 45 -15 89 6 66 0 -1431533(garbage)
			    //=============================================
	return 0;
}

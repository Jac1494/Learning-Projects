// Nested namespaces
#include <iostream>
using namespace std;

// Till C++17
// namespace A {
//   namespace B {
//     namespace C {
//       int i;
//     }
//   }
// }

// With C++17
namespace A::B::C {
	int i;
}

int main()
{
	return 0;
}

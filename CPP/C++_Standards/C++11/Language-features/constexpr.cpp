/*
 *  constexpr
 */  

// int arr[6];   //Ok
// int A() { return 3;}
// int arr[A()+3];   //Compile Error (error: variable length array declaration not allowed at file scope)

// C++ 11

constexpr int A() { return 3;} //Forces the computaion to happen 
				   // at compile time.

int arr[A()+3]; // Create an array of size 6

//Write faster program with constexpr

constexpr int cubed1(int x) { return x*x*x; }
int cubed2(int x) { return x*x*x; }
int y1= cubed1(2); // Computed at compile time // No method in assemble
int y2= cubed2(3); // Assembly generated it will resolved later stage.
int main(){}

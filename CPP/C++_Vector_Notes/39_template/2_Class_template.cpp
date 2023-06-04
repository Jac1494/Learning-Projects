#include<iostream>
using namespace std;

// Class templates
template < class T >
class Calculator{
   public:
   T x,y;

   Calculator(T a, T b):x(a),y(b){}
 
   T addition() { return x + y; }
   T Substraction() { return x - y; }
   T Multiplication() { return x * y; }
   T Division() { return x / y; }

};

int main(){

  Calculator ob(22,11);
  cout << " X - " << ob.x << " | Y - " << ob.y << "\n";
  cout << "========================="<< "\n";
  cout << "addition of X and Y "<< ob.addition() << "\n";
  cout << "Substraction of X and Y "<< ob.Substraction() << "\n";
  cout << "Multiplication of X and Y "<< ob.Multiplication() << "\n";
  cout << "Division of X and Y "<< ob.Division() << "\n";  
  cout << "========================="<< "\n";

  return 0;
}

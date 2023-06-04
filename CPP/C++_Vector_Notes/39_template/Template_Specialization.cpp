//Template Specialization
/*
While programming using templates, we might be faced with a situation such that we might require a special implementation for a particular data type. When such a situation occurs, 
we go for template specialization.

In template specialization, we implement a special behavior for a particular data type apart 
from the original template definition for the other data types.

For Example, consider we have a template class ‘myIncrement’ which has a constructor to initialize a value 
and a template function toIncrement that increments the value by 1.

This particular class will work perfectly for all the data types except for char. 
Instead of incrementing the value for char, why not give it a special behavior and 
convert the character to uppercase instead?

In order to do this, we can go for template specialization for the char data type.

This implementation is shown in the below code Example.
*/
#include <iostream>
using namespace std;
 
// class template:
template <class T>
class myIncrement {
  T value;
  public:
  myIncrement (T arg) {value=arg;}
  T toIncrement () {return ++value;}
};
// class template specialization:
template <>
class myIncrement <char> {
  char value;
  public:
   myIncrement (char arg) {value=arg;}
   char uppercase ()
  {
    if ((value>='a')&&(value<='z'))
    value+='A'-'a';
    return value;
  }
};
int main () {
  myIncrement<int> myint (7);
  myIncrement<char> mychar ('s');
  myIncrement<double> mydouble(11.0);
  
  cout<<"Incremented int value: "<< myint.toIncrement()<< endl;
  cout<<"Uppercase value: "<<mychar.uppercase()<< endl;
  cout<<"Incremented double value: "<<mydouble.toIncrement()<< endl;
  return 0;
}
/*
Output:

Incremented int value: 8
Uppercase value: S
Incremented double value: 12

template_specialization

In the above program that demonstrates template specialization, see the way in which we have declared 
a specialized template for char type.We first declare the original class and 
then we “specialize” it for char type. To begin specialization we use empty template declaration “template<>”.

Then after the class name, we include the data type <char>. After these two changes, 
the class is written for the char type.

In the main function, note that there is no difference between instantiation of char type and other types. 
The only difference is that we redefine the specialized class.

Note that we must define all the members of the specialized class even though they are exactly the same 
in the generic/original template class. This is because we do not have inheritance feature for members 
from the generic template to the specialized template.
*/

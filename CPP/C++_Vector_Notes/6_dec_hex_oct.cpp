#include<iostream>
using namespace std;

/*
- Stream is flow of data or it is interface between between two ends

1. cin  -> Object of istream class
2. cout -> Object of Ostream class
3. cerr -> Object of Ostream class

Note:-
 Difference between std::endl and "\n"

 1. std::endl ->  set curser into new line and "flush" STD_OUT buffer. 
 2. "\n"      ->  set curser into new line

*/

#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "Enter number :- \n";
   cin >> dec >> num; // This way we can scan dec , oct , hex number
   
   cout << " Decimal of the number " << dec << num << "\n";
   cout << " Octal of the number " << oct << num << "\n";
   cout << " Hexadecimal of the number " << hex << num << "\n";
   return 0;
}

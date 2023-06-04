#include<iostream>
using namespace std;

/*
Exception Handling:-
- It occurs at runtime due to ususual condtions.
- To handle such exception , Exception handling mechanisum is used.
- Syntax:-
  try
  {
    throw exception_occured;
  }
  catch(datatype argument)
  {

  }
- For handle all exception we can use
  catch(...)
  {

  }
*/

int main(){

int x,y,z;
cout << "Enter the two values\n";

cin >> x >> y;

    try
    {
        if(y == 0)
            throw "Divide by zero exception\n";
        else
            z=x/y;
    }
    catch(const char *p)
    {
        cout << p <<"\n";
        return 0;
    }

    cout << "Z - " << z << "\n";
  return 0;
}


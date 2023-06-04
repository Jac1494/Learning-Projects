/*
Template syntax for lambdas:-
Use familiar template syntax in lambda expressions.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int x=99;

    auto print = []<typename T>(T a){
        cout << "Value - " << a << "\n";
    };

    print(x);           // 99

    return 0;   
}

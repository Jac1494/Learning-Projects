#include<iostream>
#include<bitset>
using namespace std;

int main()
{
// 1. Types of Integer
    cout << sizeof(short int) << "\n";     // 2
    cout << sizeof(int) << "\n";           // 4
    cout << sizeof(long int) << "\n";      // 8
    cout << sizeof(long long int) << "\n"; // 8
    //cout << sizeof(long long long int) << "\n"; // Error

// 2. Print binary in C++
    // How many bits we need that we need to pass bitset<16>   
    bitset<8> bin1{0xFF},bin2{10};
    cout << bin1 << "\n";                  // 11111111
    cout << bin2 << "\n";                  // 00001010
   
}

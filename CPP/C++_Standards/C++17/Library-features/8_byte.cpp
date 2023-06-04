/*
std::byte:-
- The new std::byte type provides a standard way of representing data as a byte. 
  Benefits of using std::byte over char or unsigned char is that it is not a character 
  type, and is also not an arithmetic type; while the only operator overloads available 
  are bitwise operations.
- Note that std::byte is simply an enum, and braced initialization of enums 
  become possible thanks to direct-list-initialization of enums.  
*/

#include <iostream>
#include <cstddef>
#include <bitset>

// To print byte we need below cout implementation
// It will not work with normal cout  
std::ostream& operator<< (std::ostream& os, std::byte b) {
    return os << std::bitset<8>(std::to_integer<int>(b));
}
 
int main()
{
    std::byte b{42};
    std::cout << "1. " << b << '\n';
 
    // b *= 2 compilation error
    b <<= 1;
    std::cout << "2. " << b << '\n';
 
    b >>= 1;
    std::cout << "3. " << b << '\n';
 
    std::cout << "4. " << (b << 1) << '\n';
    std::cout << "5. " << (b >> 1) << '\n';
 
    b |= std::byte{0b11110000};
    std::cout << "6. " << b << '\n';
 
    b &= std::byte{0b11110000};
    std::cout << "7. " << b << '\n';
 
    b ^= std::byte{0b11111111};
    std::cout << "8. " << b << '\n';
    
    return 0;
}
/*
1. 00101010
2. 01010100
3. 00101010
4. 01010100
5. 00010101
6. 11111010
7. 11110000
8. 00001111
*/
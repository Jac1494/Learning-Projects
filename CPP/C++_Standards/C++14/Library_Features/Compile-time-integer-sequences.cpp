/*
Compile-time integer sequences:-
- The class template std::integer_sequence represents a compile-time sequence of integers. There are a few helpers built on top:

1. std::make_integer_sequence<T, N> - creates a sequence of 0, ..., N - 1 with type T.
2. std::index_sequence_for<T...> - converts a template parameter pack into an integer sequence.
*/

#include <tuple>
#include <iostream>
#include <array>
#include <utility>
 
template<typename T, T... ints>
void print_sequence(std::integer_sequence<T, ints...> int_seq)
{
    std::cout << "The sequence of size " << int_seq.size() << ": ";
    ((std::cout << ints << ' '), ...);
    std::cout << '\n';
}
 
int main()
{
    print_sequence(std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{});
    print_sequence(std::make_integer_sequence<int, 20>{});
    print_sequence(std::make_index_sequence<10>{});
    print_sequence(std::index_sequence_for<float, std::iostream, char>{}); 
    print_sequence(std::index_sequence_for<int,float>{}); // How many value's are there it will count like that
    return 0; 
}
/*
The sequence of size 7: 9 2 5 1 9 1 6 
The sequence of size 20: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
The sequence of size 10: 0 1 2 3 4 5 6 7 8 9 
The sequence of size 3: 0 1 2 
The sequence of size 2: 0 1 
*/
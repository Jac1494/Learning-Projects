/*
std::sample:-
- Samples n elements in the given sequence (without replacement) where every element 
  has an equal chance of being selected.

*/

#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>

int main()
{
	std::string in = "ABCDEFGHIJK", out;
	std::sample(in.begin(), in.end(), std::back_inserter(out), 4,
			std::mt19937{std::random_device{}()});
	std::cout << "Four random letters out of " << in << " : " << out << '\n';
}

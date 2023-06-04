// TODO
/*
Parallel algorithms:-
- Many of the STL algorithms, such as the copy, find and sort methods, 
 started to support the parallel execution policies: seq, par and par_unseq 
 which translate to "sequentially", "parallel" and "parallel unsequenced".
- https://devblogs.microsoft.com/cppblog/using-c17-parallel-algorithms-for-better-performance/
*/

#include <iostream>
#include <vector>
#include <execution>
using namespace std;

int main() {

	std::vector<int> longVector;
	// Find element using parallel execution policy
	auto result1 = std::find(std::execution::par, std::begin(longVector), std::end(longVector), 2);
	// Sort elements using sequential execution policy
	// auto result2 = std::sort(std::execution::seq, std::begin(longVector), std::end(longVector));

	return 0;
}

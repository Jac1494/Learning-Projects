/*
Set:-
- Sets are a type of associative container in which each element has to 
  be unique because the value of the element identifies it. The values 
  are stored in a specific sorted order i.e. either ascending or descending.
- It is defined inside the <set> header file.
- set does not take multiple same values it only accepts a unique value. 
  We can use Multiset if we want to store multiple same values.
  
Syntax:-
    std::set <data_type> set_name;
- Datatype: Set can take any data type depending on the values, e.g. int, char, float, etc.

Properties:-
Storing order – The set stores the elements in sorted order.
Values Characteristics – All the elements in a set have unique values.
Values Nature – The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
Search Technique – Sets follow the Binary search tree implementation.
Arranging order – The values in a set are unindexed.

Set 								    
- Set stores elements in a sorted order	
- Set stores/acquire unique elements only	
- Set uses Binary Search Trees for implementation	
- More than one element can be erased by giving the starting and ending iterator	
- set<datatype> Set_Name;	

Vs

Unordered Set
- Unordered Set stores elements in an unsorted order
- Unordered Set stores/acquire only unique values
- Unordered Set uses Hash Tables for implementation
- We can erase that element for which the iterator position is given
- unordered_set<datatype> UnorderedSet_Name;
*/

#include <iostream>
#include <set>

int main()
{
	std::set<char> a;
	a.insert('G');
	a.insert('F');
	a.insert('G');
	for (auto& str : a) {
		std::cout << str << ' ';    // F G
	}
	std::cout << '\n';
	return 0;
/*
Time complexity: O(N) // N is the size of the set.
Auxiliary Space: O(N)
*/    
}

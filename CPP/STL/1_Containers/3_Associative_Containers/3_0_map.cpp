/*
Map:-
- Maps are associative containers that store elements in a mapped fashion. 
  Each element has a key value and a mapped value. 
- No two mapped values can have the same key values.
*/

#include <iostream>
#include <map>

int main()
{
	// Create a map of strings to integers
	std::map<std::string, int> map;

	// Insert some values into the map
	map["one"] = 1;
	map["two"] = 2;
	map["three"] = 4;  // It will work but it will store last update value means three
	map["three"] = 3;

	// Get an iterator pointing to the first element in the map
	std::map<std::string, int>::iterator it = map.begin();

	// Iterate through the map and print the elements
	while (it != map.end())
	{
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		++it;
	}
	// Why it is giving three first check that
	/*
Key: one, Value: 1
Key: three, Value: 3
Key: two, Value: 2
Time complexity: O(n) //where n is the size of map.
Auxiliary Space: O(n)
*/

	// Print the size of the map
	std::cout << "Size of map: " << map.size() << std::endl;  // 3 


	// Check if a key is in the map
	if (map.count("four") > 0)
	{
		std::cout << "Key 'four' is in the map" << std::endl;
	}
	else
	{
		std::cout << "Key 'four' is not in the map" << std::endl;  // True
	}

	// lower bound and upper bound for map key = three
	std::cout << "map.lower_bound(two) : " << "\tKEY = "; 
	std::cout << map.lower_bound("two")->first << '\t';        // two
	std::cout << "\tELEMENT = " << map.lower_bound("two")->second << "\n";  // 2     

	map.erase(map.begin(), map.find("three"));

	it = map.begin();

	// Iterate through the map and print the elements
	while (it != map.end())
	{
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		++it;
		/*
Key: three, Value: 3
Key: two, Value: 2
*/    
	}
	return 0;
}


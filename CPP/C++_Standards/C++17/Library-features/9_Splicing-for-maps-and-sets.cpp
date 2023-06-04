/*
Splicing for maps and sets:-
- It's helpful updates that can bring performance improvements and cleaner code.  
- The first example is that you can now move nodes from one tree-based container 
  (maps/sets) into other ones, without additional memory overhead/allocation.
*/

#include <map>
#include <string>
#include <iostream>
using namespace std;

void print(map<int, string> mp)
{
    for (auto& elem : mp)
        cout << elem.first << " => " << elem.second << '\n';     
}
int main() {

    // Example - 1     
    map<int, string> src {{1, "one"}, {2, "two"}, {4, "four"}};
    map<int, string> dst {{3, "three"}};
    
    cout << "======== 00 ========\n";
    print(src);
    print(dst);
    //cout << "===================\n";
    //print(dst);
    dst.insert(src.extract(src.find(1))); // Cheap remove and insert of { 1, "one" } from `src` to `dst`.
    //cout << "===================\n";
    //print(dst);
    dst.insert(src.extract(2)); // Cheap remove and insert of { 2, "two" } from `src` to `dst`.
    // dst == { { 1, "one" }, { 2, "two" }, { 3, "three" } };                                         
    //cout << "===================\n";
    //print(dst);
    cout << "======== 11 ========\n";
    print(src);
    print(dst);
    cout << "======== 22 ========\n";
    dst.merge(src);
    print(dst);

    auto e = dst.extract(1);
    e.key() = 11;
    dst.insert(std::move(e));
    cout << "======== 33 ========\n";
    print(dst);

    return 0;
}
/*
======== 00 ========
1 => one
2 => two
4 => four
3 => three
======== 11 ========
4 => four
1 => one
2 => two
3 => three
======== 22 ========
1 => one
2 => two
3 => three
4 => four
======== 33 ========
2 => two
3 => three
4 => four
11 => one
*/

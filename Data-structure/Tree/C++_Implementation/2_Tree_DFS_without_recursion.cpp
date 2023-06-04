#include<iostream>
#include"BST.cpp"
using namespace std;

int main() {
    BST DfsNode;
    DfsNode.insert(3);
    DfsNode.insert(4);
    DfsNode.insert(5);
    DfsNode.insert(1);
    DfsNode.insert(2);

    cout << "=========>  With out recursion  <=========="<< "\n";
    
    cout << "Pre-Order traversal of the DFS:-  ";
    DfsNode.preorderTraversal(); // 3 1 2 4 5
    cout << "\n";
    cout << "In-Order traversal of the DFS:-   ";
    DfsNode.inorderTraversal(); // 1 2 3 4 5
    cout << "\n";
    cout << "Post-Order traversal of the DFS:- ";
    DfsNode.postorderTraversal(); // 2 1 5 4 3
    cout << "\n";

    cout << "==========================================="<< "\n";

    return 0;
}
/*
=========>  With out recursion  <==========
Pre-Order traversal of the DFS:-  3 1 2 4 5 
In-Order traversal of the DFS:-   1 2 3 4 5 
Post-Order traversal of the DFS:- 2 1 5 4 3 
===========================================
*/

#include<iostream>
#include"BST.cpp"
using namespace std;

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);

    bst.inorderTraversal(); // 1 3 5 7 9
    cout << endl;

    TreeNode* node = bst.search(3);
    if (node) {
        cout << "Found node with value " << node->val << endl;
    }
    else {
        cout << "Node not found" << endl;
    }

    return 0;
}

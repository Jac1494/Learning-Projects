#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
    TreeNode* root;

public:
    BST() {
        root = NULL;
    }
	void insert(int val);
	void inorder(TreeNode* node);
	void preorder(TreeNode* node);
	void postorder(TreeNode* node);
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();
	void preorder_without_Recursion(TreeNode* root);
	void inorder_without_Recursion(TreeNode* root);
	void postorder_without_Recursion(TreeNode* root);
	void preorderTraversalwithoutRecursion();
	void inorderTraversalwithoutRecursion();
	void postorderTraversalwithoutRecursion();
	TreeNode* search(int val);
	TreeNode* searchHelper(TreeNode* node, int val);
};

void BST::insert(int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return;
    }
    TreeNode* curr = root;
    while (curr != NULL) {
        if (val < curr->val) {
            if (curr->left == NULL) {
                curr->left = new TreeNode(val);
                return;
            }
            curr = curr->left;          //Traverse tree upto new value we want to add
        }
        else {
            if (curr->right == NULL) {
                curr->right = new TreeNode(val);
                return;
            }
            curr = curr->right;          //Traverse tree upto new value we want to add
        }
    }
}

void BST::inorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

void BST::preorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->val << " ";
}

void BST::inorderTraversal() {
    inorder(root);
}

void BST::preorderTraversal() {
    preorder(root);
}

void BST::postorderTraversal() {
    postorder(root);
}

///////////// Without Recursion ///////////////////////
void BST::preorder_without_Recursion(TreeNode* root) {

    stack<TreeNode*> s;
    TreeNode*curr = root;
    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) {
        cout << curr->val << " ";
        s.push(curr);
        curr = curr->left;
        }
        curr = s.top();
        s.pop();

        curr = curr->right;
    }
}

void BST::inorder_without_Recursion(TreeNode* root) {

    stack<TreeNode*> s;
    TreeNode*curr = root;
    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) {
        s.push(curr);
        curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";

        curr = curr->right;
    }
}

void BST::postorder_without_Recursion(TreeNode* root) {

    stack<TreeNode*> s;
    TreeNode*previous = NULL;
    do {
        while (root != NULL) {
        //          cout <<  " tt1 "<< root->data <<"\n";
        s.push(root);
        root = root->left;
        }

        while (root == NULL && !s.empty()) {
        root = s.top();
        // cout <<  "\ns.top " << root->data <<"\t";
        if (root->right == NULL || root->right == previous) {
            cout << root->val << " ";
            s.pop();
            previous = root;
            root = NULL;
        } else
            root = root->right;
        }
    } while (!s.empty());
}

void BST::preorderTraversalwithoutRecursion() {
    preorder_without_Recursion(root);
}

void BST::inorderTraversalwithoutRecursion() {
    inorder_without_Recursion(root);
}

void BST::postorderTraversalwithoutRecursion() {
    postorder_without_Recursion(root);
}

TreeNode* BST::search(int val) {
	return searchHelper(root, val);
}

TreeNode* BST::searchHelper(TreeNode* node, int val) {
	if (node == NULL || node->val == val) {
		return node;
	}
	if (val < node->val) {
		return searchHelper(node->left, val);
	}
	else {
		return searchHelper(node->right, val);
	}
}

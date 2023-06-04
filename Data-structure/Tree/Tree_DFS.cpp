// Depth-First Search (DFS)

#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

void Preorder(struct Node *root) {

  if (root != NULL) {
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
  }
}
void Preorder_without_Recursion(struct Node *root) {

  stack<Node *> s;
  Node *curr = root;
  while (curr != NULL || s.empty() == false) {
    while (curr != NULL) {
      cout << curr->data << " ";
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();

    curr = curr->right;
  }
}

void Inorder(struct Node *root) {
  if (root != NULL) {
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
  }
}
void Inorder_without_Recursion(struct Node *root) {

  stack<Node *> s;
  Node *curr = root;
  while (curr != NULL || s.empty() == false) {
    while (curr != NULL) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    cout << curr->data << " ";

    curr = curr->right;
  }
}

void Postorder(struct Node *root) {

  if (root != NULL) {
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
  }
}
void Postorder_without_Recursion(struct Node *root) {

  stack<Node *> s;
  Node *previous = NULL;
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
        cout << root->data << " ";
        s.pop();
        previous = root;
        root = NULL;
      } else
        root = root->right;
    }
  } while (!s.empty());
}

struct Node *InsertNode(struct Node *Node, int val) {

  if (Node == NULL) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
  }

  if (val < Node->data)
    Node->left = InsertNode(Node->left, val);
  else if (val > Node->data)
    Node->right = InsertNode(Node->right, val);

  return Node;
}

int main() {
  struct Node *root = NULL;
  root = InsertNode(root, 3);
  root = InsertNode(root, 4);
  root = InsertNode(root, 5);
  root = InsertNode(root, 1);
  root = InsertNode(root, 2);

       /*
	              3
                  1	    4
                         2	5
       */
  cout << "=========>  With recursion  <==========="
       << "\n";
  cout << "Pre-Order traversal of the BST:- ";
  Preorder(root);
  cout << "\n";
  cout << "In-Order traversal of the BST:- ";
  Inorder(root);
  cout << "\n";
  cout << "Post-Order traversal of the BST:- ";
  Postorder(root);
  cout << "\n\n";

  cout << "=========>  Without recursion  <========="
       << "\n";
  cout << "Pre-Order traversal of the BST:- ";
  Preorder_without_Recursion(root);
  cout << "\n";
  cout << "In-Order traversal of the BST:- ";
  Inorder_without_Recursion(root);
  cout << "\n";
  cout << "Post-Order traversal of the BST:- ";
  Postorder_without_Recursion(root);
  return 0;
}

/*
Output:-

Pre-Order traversal of the BST:- 3 1 2 4 5
In-Order traversal of the BST:- 1 2 3 4 5
Post-Order traversal of the BST:- 2 1 5 4 3
========= Without recursion =========
Pre-Order traversal of the BST:- 3 1 2 4 5
In-Order traversal of the BST:- 1 2 3 4 5
Post-Order traversal of the BST:- 2 1 5 4 3

*/

// Breadth-First Search (BFS)

#include <iostream>
#include <queue>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};
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
  root = InsertNode(root, 1);
  root = InsertNode(root, 2);
  root = InsertNode(root, 3);
  root = InsertNode(root, 4);
  root = InsertNode(root, 5);

  cout << "Level Order traversal of binary tree is \n";
  queue<Node *> q;
  q.push(root);
  while (q.empty() == false) {
    Node *node = q.front();
    cout << node->data << " ";
    q.pop();
    if (node->left != NULL)
      q.push(node->left);
    if (node->right != NULL)
      q.push(node->right);
  }
  return 0;
}
/*
Output :-
Level Order traversal of binary tree is
1 2 3 4 5
*/

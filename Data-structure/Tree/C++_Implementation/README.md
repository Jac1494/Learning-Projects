What is a binary tree?
----------------------
- A binary tree is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. 
-  A binary tree is called a proper binary tree or a full binary tree if each node has exactly two children.
-  It is called a complete binary tree if all levels of the tree are completely filled except possibly the last level, which is filled from left to right.

What is a binary search tree?
-----------------------------
- A binary search tree (BST) is a binary tree in which the value of each node is greater than or equal to the values in its left subtree and less than 
  or equal to the values in its right subtree. In other words, a binary search tree is a binary tree where the left subtree contains only nodes with values   less than the parent node, and the right subtree contains only nodes with values greater than the parent node.

What is a self-balancing binary search tree? Name some types of self-balancing binary search trees and explain their differences.
-----------------------------
- A self-balancing binary search tree (BST) is a binary search tree that automatically maintains a balanced tree structure, typically by performing tree rotations to keep the tree height as small as possible. A balanced tree has the property that the height of its left and right subtrees differ by at most 1.

- There are several types of self-balancing binary search trees, some of which include:

  **1. AVL tree:** Named after its inventors, Adelson-Velsky and Landis, the AVL tree is the first data structure designed to maintain a balanced binary search tree. In an AVL tree, the difference between the heights of the left and right subtrees of any node is at most 1, and the balance factor of a node is defined as the difference between the height of its left subtree and the height of its right subtree. If a node's balance factor is greater than 1 or less than -1, the tree is unbalanced and requires rebalancing operations, such as tree rotations, to restore balance. The AVL tree has a worst-case time complexity of O(log n) for search, insert, and delete operations.

  **2. Red-black tree:** A red-black tree is a self-balancing binary search tree in which each node is colored red or black. The tree is balanced by ensuring that the longest path from the root to a leaf is no more than twice as long as the shortest path from the root to a leaf. Red-black trees are designed to be more efficient than AVL trees in terms of insertion and deletion operations. A red-black tree has a worst-case time complexity of O(log n) for search, insert, and delete operations.

  **3. Splay tree:** A splay tree is a self-adjusting binary search tree in which frequently accessed nodes are moved closer to the root to reduce access time. A splay operation is performed on a node whenever it is accessed, which moves the node to the root of the tree. Splay trees have no balancing condition, and the height of a splay tree can be unbalanced in the worst case. However, splay trees are designed to be more efficient than AVL trees and red-black trees in practice due to their simplicity and frequent node access.

  **4. Treap:** A treap is a randomized binary search tree in which each node has a priority value assigned to it. The tree is balanced by maintaining the heap property based on the priority values of the nodes, and the search tree property is maintained by the binary search tree structure. The height of a treap is logarithmic in expectation, and the tree has a worst-case time complexity of O(log n) for search, insert, and delete operations.

 - Each type of self-balancing binary search tree has its own advantages and disadvantages, and the choice of which one to use depends on the specific requirements of the application. AVL trees are guaranteed to maintain perfect balance but require more rotations than red-black trees. Red-black trees are simpler to implement and generally perform better than AVL trees for insertion and deletion operations. Splay trees are simple and efficient for frequently accessed nodes but have no balance guarantee. Treaps are randomized and can maintain balance in expectation but have a more complicated implementation.

What is a trie? How is it useful in searching for words?
-----------------------------
- A trie (pronounced "try") is a tree-like data structure used to store and retrieve strings. It is particularly useful for searching for words in a dictionary or set of words because it can search for prefixes of words efficiently.

- In a trie, each node represents a character in a string, and the edges leading from that node represent the possible next characters in the string. The root node represents an empty string, and each leaf node represents a complete word. The trie structure allows for quick searches of all the words that have a common prefix.

- To search for a word in a trie, we start at the root node and follow the edges that correspond to the characters in the word we are searching for. If we reach a leaf node, we know that the word is in the trie. If we follow a path that does not exist in the trie, we know that the word is not in the trie.

- For example, let's say we have a trie containing the words "apple", "application", and "banana". If we want to search for the prefix "app", we start at the root node and follow the edge for "a", then the edge for "p", and finally the edge for "p". We arrive at a node that represents the prefix "app", and we can traverse the subtree rooted at that node to find all the words with that prefix.

- Tries can be implemented efficiently using a node structure that contains an array of pointers to its child nodes, one for each possible character in the strings being stored. The time complexity for searching for a word in a trie is O(m), where m is the length of the word being searched for, which is faster than searching for a word in a hash table or a binary search tree.

What is a heap? Explain the difference between a min heap and a max heap.
-----------------------------
- A heap is a specialized tree-based data structure that is used to maintain a collection of elements with a priority order. The heap data structure is commonly used in algorithms such as heap sort, priority queues, and graph algorithms.

- In a heap, each node represents an element in the collection, and the relationship between nodes is defined by a comparison function. The comparison function determines the priority order of the elements in the heap. In most heap implementations, the comparison function is such that the parent node has a higher priority than its children nodes.

- A heap can be implemented using an array or a binary tree. In a binary heap implementation, each node has at most two child nodes, and the tree is complete. A complete binary tree is a binary tree in which all levels except possibly the last level are completely filled, and all nodes are as far left as possible.

- There are two types of heaps: min heap and max heap. The difference between a min heap and a max heap is in the order of the elements.

  **1) In a min heap**, the parent node has a lower priority than its children nodes. In other words, the minimum element is always stored at the root of the heap. For example, if we have a min heap containing the elements {2, 5, 7, 8, 10, 11}, the root node contains the minimum element 2, and the children of each node are always greater than or equal to the parent node.

  **2) In a max heap**, the parent node has a higher priority than its children nodes. In other words, the maximum element is always stored at the root of the heap. For example, if we have a max heap containing the elements {11, 10, 7, 5, 8, 2}, the root node contains the maximum element 11, and the children of each node are always less than or equal to the parent node.

- Both min heap and max heap have the property that the height of the tree is always logarithmic to the number of elements in the heap, and the time complexity of inserting or extracting the minimum or maximum element is O(log n), where n is the number of elements in the heap.

What is an AVL tree? How is it different from a binary search tree?
-----------------------------
- An AVL (Adelson-Velsky and Landis) tree is a type of self-balancing binary search tree. It is named after the inventors who proposed it in 1962. An AVL tree is similar to a binary search tree in that it maintains an ordered collection of elements with efficient search, insert, and delete operations. However, unlike a regular binary search tree, an AVL tree is guaranteed to be balanced, which ensures efficient operations.

- A binary search tree can become unbalanced if the elements are inserted in a specific order or if some elements are frequently accessed, leading to poor performance. In contrast, an AVL tree balances itself after each insertion or deletion operation, ensuring that the tree remains balanced. An AVL tree is balanced in such a way that the height difference between the left and right subtrees of every node is at most 1.

- In an AVL tree, each node has a balance factor, which is the difference between the height of the left and right subtrees. The balance factor can be -1, 0, or 1. When a node is inserted or deleted, the balance factor of each node in the path from the root to the newly inserted or deleted node is checked. If the balance factor of any node is outside the range of -1 to 1, the tree is rebalanced by rotating the nodes in the tree.

- The operations on an AVL tree have a time complexity of O(log n) in the worst case, where n is the number of nodes in the tree. This is because the height of an AVL tree is always logarithmic to the number of nodes in the tree.

- In summary, an AVL tree is a self-balancing binary search tree that ensures efficient search, insert, and delete operations by maintaining a balanced tree structure. This balance is achieved by performing rotations on nodes in the tree when necessary, based on the balance factor of each node.

What is a Red-Black tree? How does it maintain balance?
-----------------------------
- A Red-Black tree is a type of self-balancing binary search tree that ensures efficient search, insertion, and deletion operations by maintaining a balanced tree structure. It was invented by Rudolf Bayer in 1972.

- A Red-Black tree is similar to an AVL tree in that it ensures that the tree remains balanced, but it is more relaxed in terms of balancing requirements. A Red-Black tree achieves balance by coloring each node with either red or black, hence the name. 
- The tree satisfies the following properties:

  1. Every node is colored either red or black.
  2. The root of the tree is black.
  3. Every leaf (NIL node) is black.
  4. If a node is red, then both its children are black.
  5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes (the black-height of the node).

- The key to maintaining balance in a Red-Black tree is to ensure that the black-height of every node is the same, which is achieved by coloring the nodes in a way that satisfies the above properties. When a node is inserted or deleted, the tree may become unbalanced, violating one of the properties. The tree is rebalanced by performing a series of rotations and color flips to restore the properties.

- The insertion and deletion operations on a Red-Black tree have a time complexity of O(log n) in the worst case, where n is the number of nodes in the tree. This is because the height of a Red-Black tree is always logarithmic to the number of nodes in the tree.

- In summary, a Red-Black tree is a type of self-balancing binary search tree that ensures efficient search, insertion, and deletion operations by maintaining a balanced tree structure through a series of colorings and rotations. The tree's balance is achieved by coloring each node red or black, following the properties of a Red-Black tree.

-----------------------------
-----------------------------

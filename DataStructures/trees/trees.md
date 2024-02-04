# Tree

[Tree (data structure)](https://en.wikipedia.org/wiki/Tree_(data_structure))

## Binary Tree

A **Binary Tree** is a hierarchical data structure composed of nodes, where each node has at most two child nodes (children), and it does not have any order.

### Properties / Terms

- **`Edge` :** An edge is a connection between two nodes. It represents the link or relationship between a parent node and its child node in a binary tree. Each edge in a binary tree corresponds to either the left or right child of a node.

- **`Node` :** Each element in a binary tree is called a node. A node typically contains data and may have references (pointers) to its left and right children.

- **`Root` :** The topmost node in a binary tree is called the root. It is the starting point for traversing the tree.

- **`Leaf Node` :** A leaf node is a node that has no children. In other words, it is a node without a left or right child.

- **`Internal Node` :** An internal node is a node that has at least one child (either left or right or both), but it is not a leaf node.

- **`Parent Node` :** A node in a binary tree that has one or more child nodes is referred to as a parent node.

- **`Child Node` :** The nodes directly connected to another node are its children. In a binary tree, a node can have at most two children: a left child and a right child.

- **`Sibling Nodes` :** Nodes that share the same parent are called siblings.

- **`Ancestor` :** An ancestor of a given node is any node that lies on the path from the root of the tree to that node. In other words, an ancestor is a node that is closer to the root than the specified node.


```text
      1
     / \
    2   3
   / \
  4   5
 / \
6   7
```

- The ancestors of node 6 are nodes 4, 2, and 1.
- The ancestors of node 2 are node 1.
- So when finding a path form `a` to `b`, `a` is the ancestor of `b`.
- **IMP Question On Ancestors** Lowest common ancestor of a binary tree.

- **`Descendant` :** A descendant of a given node is any node that lies below it in the tree hierarchy. In other words, a descendant is a node that is reached by following a path from the specified node.

```text
      1
     / \
    2   3
   / \
  4   5
 / \
6   7
```

- The descendants of node 1 are nodes 2, 3, 4, 5, 6, and 7.
- The descendants of node 4 are nodes 6 and 7.
- When finding a path form `a` to `b`, `b` is the descendant of `a`.

- **`Depth` :** The depth of a node in a binary tree is the length of the path from the root to that node. The depth of the root node is 0.

- **`Height (or Depth of the Tree)` :** The height of a binary tree is the length of the longest path from the root node to a leaf node. It is also defined as the depth of the deepest node in the tree.

- **`Level` :** The level of a node in a binary tree is a measure of its position in the tree hierarchy. It represents the distance of that node from the root node, where the root node is considered to be at level 0.

  - **`Root Node (Level 0)` :** The topmost node in a binary tree is called the root node, and it is assigned level 0. This is the starting point for measuring the distance of other nodes within the tree.

  - **`Children of the Root (Level 1)` :** Nodes that are directly connected to the root node are considered to be at level 1. These are the immediate descendants of the root.

  - **`Grandchildren of the Root (Level 2)` :** Nodes that are two edges away from the root (children of the children) are at level 2. This pattern continues, and nodes that are three edges away are at level 3, and so on.


```text
        1 (Level 0)
       / \
      2   3 (Level 1)
     / \
    4   5 (Level 2)
   /
  6   (Level 3)
```

In this example:

- Node 1 is at level 0 (the root).
- Nodes 2 and 3 are at level 1 (children of the root).
- Nodes 4 and 5 are at level 2 (children of nodes 2 and 3).
- Node 6 is at level 3 (a grandchild of node 2).

So, when saying 'the level of a node is the distance from the root,' it means counting the number of edges from the root to that node. This concept aids in understanding the relative position of nodes within the binary tree structure.

- **`Sub-tree` :** A sub-tree is a tree formed by a node and all its descendants.

```text
    1 (Root)(Main Family Tree)
   / \
  2   3
 / \
4   5
 \
  6
```

- The entire family tree is rooted at member 1 (the root).
- The sub-tree rooted at member 2 includes members 2, 4, 5, and 6 (all the descendants of 2).
- The sub-tree rooted at member 4 includes members 4 and 6 (all the descendants of 4).
- The sub-tree rooted at member 3 includes only member 3.
- In simpler words a sub-tree is like a small family branch starting from a specific family member and including all of their family.

## Traversing a Binary Tree (Tree traversal).

[Michael Sambol](https://www.youtube.com/watch?v=1WxLM2hwL-U)

- Tree `traversal` is a systematic way of visiting nodes in a `tree`.

### Preorder Tree Traversal

- **Preorder traversal** involves visiting the nodes of a tree in the following order:
  1. Visit the node.
  2. Traverse left sub-tree.
  3. Traverse right sub-tree.

- **Visualization** :
  - The current node is visited first, then the left subtree is explored, and finally, the right subtree is explored.
  - Consider this tree, and when a `node` is visited, `print` the `value` of that `node`, to indicated that it is visited.
  ```text
         1   
       /   \
      2     3
     / \   / \ 
    4   5  6  7
  ```
  - `preorder` traversal for the above tree is : 1 2 4 5 3 6 7.

### Inorder

- **Inorder traversal** involves visiting the nodes of a tree in the following order:
  1. Traverse left sub-tree.
  2. Visit the node.
  3. Traverse right sub-tree.

- **Visualization** :
  - The left subtree is explored first, then the current node is visited, and finally, the right subtree is explored.
  - Consider this tree, and when a `node` is visited, `print` the `value` of that `node`, to indicated that it is visited.
  ```text
         1   
       /   \
      2     3
     / \   / \ 
    4   5  6  7
  ```
  - `inorder` traversal for the above tree is : 4 2 5 1 6 3 7.


### Postorder

- **Postorder traversal** involves visiting the nodes of a tree in the following order:
  1. Traverse left sub-tree.
  2. Traverse right sub-tree.
  3. Visit the node.

- **Visualization** :
  - The left subtree is explored first, then the right subtree is explored, and finally, the current node is visited.
  - Consider this tree, and when a `node` is visited, `print` the `value` of that `node`, to indicated that it is visited.
  ```text
         1   
       /   \
      2     3
     / \   / \ 
    4   5  6  7
  ```
  - `postorder` traversal for the above tree is : 4 5 2 6 7 3 1.

### Summary:

- **Preorder** : Visit node, traverse left sub-tree, traverse right sub-tree.
- **Inorder** : Traverse left sub-tree, visit node, traverse right sub-tree.
- **Postorder** : Traverse left sub-tree, traverse right sub-tree, visit node.


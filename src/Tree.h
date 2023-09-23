#ifndef BST_TREE_H
#define BST_TREE_H

#include <iostream>

struct TreeNode {
  int key;
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;

  explicit TreeNode(int num) {
    key = num;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
};

class Tree {
 public:
  Tree();

  Tree(const Tree& tree); // Copy constructor (Rule of Five)

  Tree(Tree&& tree) noexcept; // // Move constructor using rvalue reference (Rule of Five)

  ~Tree(); // Destructor (Rule of Five)

  void copyTree(TreeNode*& destNode, const TreeNode* srcNode); // Helper for assignment operators

  Tree& operator=(Tree&& rhs) noexcept; // Move assignment operator (Rule of Five)

  Tree& operator=(const Tree& rhs); // Copy assignment operator (Rule of Five)

  TreeNode* getRoot();

  int getHeight() const;

  TreeNode* findKey(TreeNode* node, int key);

  TreeNode* findMin(TreeNode* node);

  TreeNode* findMax(TreeNode* node);

  TreeNode* findPredecessor(TreeNode* node); // Returns the node with the largest key < than provided node

  TreeNode* findSuccessor(TreeNode* node); // Returns the node with the smallest key > than provided node

  void insertNode(Tree* tree, TreeNode* node);

  void deleteNode(Tree* tree, TreeNode* node);

  void shiftNodes(Tree* tree, TreeNode* curr, TreeNode* next); // Helper for deleteNode()

 private:
  TreeNode* root = nullptr;
  int height = 0;
};

#endif // BST_TREE_H

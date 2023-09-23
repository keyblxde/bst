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

  ~Tree(); // Destructor (Rule of Three)

  Tree(const Tree& tree); // Copy constructor (Rule of Three)

  Tree& operator=(const Tree& rhs); // Copy assignment operator (Rule of Three)

  TreeNode* getRoot();

  int getHeight() const;

  TreeNode* findKey(TreeNode* node, int key);

  TreeNode* findMin(TreeNode* node);

  TreeNode* findMax(TreeNode* node);

  TreeNode* findPredecessor(TreeNode* node); // Returns the node with the largest key < than provided node

  TreeNode* findSuccessor(TreeNode* node); // Returns the node with the smallest key > than provided node

  void insertNode(Tree* tree, TreeNode* node);

  void deleteNode(Tree* tree, TreeNode* node);

 private:
  TreeNode* root = nullptr;
  int height = 0;

  void copyTree(TreeNode*& destNode, const TreeNode* srcNode); // Helper for assignment operators

  void shiftNodes(Tree* tree, TreeNode* curr, TreeNode* next); // Helper for deleteNode()
};

#endif // BST_TREE_H
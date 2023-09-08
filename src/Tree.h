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

    ~Tree();

    Tree& operator=(const Tree& rhs);

    TreeNode* getRoot();

    int getHeight() const;

    TreeNode* findKey(TreeNode* node, int key);

    TreeNode* findMin(TreeNode* node);

    TreeNode* findMax(TreeNode* node);

    TreeNode* findSuccessor(TreeNode* node);

    TreeNode* findPredecessor(TreeNode* node);

    void insertNode(Tree* tree, TreeNode* node);

    void deleteNode(Tree* tree, TreeNode* node);

private:
    TreeNode* root = nullptr;
    int height = 0;

    void shiftNodes(Tree* tree, TreeNode* curr, TreeNode* next);

    void copyTree(TreeNode*& destNode, const TreeNode* srcNode);
};


#endif // BST_TREE_H

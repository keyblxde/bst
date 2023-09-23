#include "Tree.h"

Tree::Tree() = default;

Tree::~Tree() = default;

Tree::Tree(const Tree& tree) : root(nullptr), height(0) {
  copyTree(this->root, tree.root);
  this->height = tree.height;
}

void Tree::copyTree(TreeNode*& destNode, const TreeNode* srcNode) {
  if (srcNode == nullptr) {
    destNode = nullptr;
    return;
  }

  destNode = new TreeNode(srcNode->key);

  // Recursively copy left and right subtrees
  copyTree(destNode->left, srcNode->left);
  copyTree(destNode->right, srcNode->right);

  // Update parent pointers
  if (destNode->left) {
    destNode->left->parent = destNode;
  }
  if (destNode->right) {
    destNode->right->parent = destNode;
  }
}

Tree& Tree::operator=(const Tree& rhs) {
  if (this != &rhs) {
    // Clear the current tree
    while (this->root) {
      deleteNode(this, this->root);
    }

    // Perform a deep copy of rhs
    if (rhs.root) {
      this->root = new TreeNode(rhs.root->key);
      this->height = rhs.height;

      // Recursively copy the entire tree
      copyTree(this->root, rhs.root);
    } else {
      this->root = nullptr;
      this->height = 0;
    }
  }

  return *this;
}

/* Accessors */
TreeNode* Tree::getRoot() {
  return this->root;
}

int Tree::getHeight() const {
  return this->height;
}

TreeNode* Tree::findKey(TreeNode* node, int key) {
  while (node != nullptr && key != node->key) {
    if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }

  return node;
}

TreeNode* Tree::findMin(TreeNode* node) {
  while (node->left != nullptr) {
    node = node->left;
  }

  return node;
}

TreeNode* Tree::findMax(TreeNode* node) {
  while (node->right != nullptr) {
    node = node->right;
  }

  return node;
}

TreeNode* Tree::findPredecessor(TreeNode* node) {
  if (node->left != nullptr) {
    return findMax(node->left);
  }

  // Traverses back up tree till we reach predecessor
  TreeNode* parent = node->parent;
  while (parent != nullptr && node == parent->left) {
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

TreeNode* Tree::findSuccessor(TreeNode* node) {
  if (node->right != nullptr) {
    return findMin(node->right);
  }

  // Traverses back up tree till we reach successor
  TreeNode* parent = node->parent;
  while (parent != nullptr && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

/* Mutators */
void Tree::insertNode(Tree* tree, TreeNode* node) {
  if (findKey(tree->root, node->key) == nullptr) {
    TreeNode* previous = nullptr;
    TreeNode* curr = tree->root;
    while (curr != nullptr) {
      previous = curr;
      if (node->key < curr->key) {
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }

    node->parent = previous;
    if (previous == nullptr) {
      tree->root = node;
    } else if (node->key < previous->key) {
      previous->left = node;
    } else {
      previous->right = node;
    }

    this->height++;
  }
}

void Tree::shiftNodes(Tree* tree, TreeNode* curr, TreeNode* next) {
  if (curr->parent == nullptr) {
    tree->root = curr;
  } else if (curr == curr->parent->left) {
    curr->parent->left = next;
  } else {
    curr->parent->right = next;
  }

  if (next != nullptr) {
    next->parent = curr->parent;
  }
}

void Tree::deleteNode(Tree* tree, TreeNode* node) {
  if (node->left == nullptr) {
    shiftNodes(tree, node, node->right);
  } else if (node->right == nullptr) {
    shiftNodes(tree, node, node->left);
  } else {
    TreeNode* successor = findSuccessor(node);

    if (successor->parent != node) {
      shiftNodes(tree, successor, successor->right);
      successor->right = node->right;
      successor->right->parent = successor;
    }

    shiftNodes(tree, node, successor);
    successor->left = node->left;
    successor->left->parent = successor;

    this->height--;
  }
}
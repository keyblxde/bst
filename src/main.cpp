#include <iostream>
#include "Tree.h"

void printHeight(Tree* tree) {
  std::cout << "Height: " << tree->getHeight() << std::endl;
}

void printRoot(Tree* tree) {
  std::cout << "Root: " << tree->getRoot()->key << std::endl;
}

void printMin(Tree* tree) {
  std::cout << "Min Key: " << tree->findMin(tree->getRoot())->key << std::endl;
}

void printMax(Tree* tree) {
  std::cout << "Max Key: " << tree->findMax(tree->getRoot())->key << std::endl;
}

void printPredecessor(Tree* tree) {
  std::cout << "Preceding Node Key: " << tree->findPredecessor(tree->getRoot())->key << std::endl;
}

void printSuccessor(Tree* tree) {
  std::cout << "Preceding Node Key: " << tree->findSuccessor(tree->getRoot())->key << std::endl;
}

int main() {
  // Test node insertion
  Tree* t1 = new Tree();
  t1->insertNode(t1, new TreeNode(2));
  t1->insertNode(t1, new TreeNode(1));
  t1->insertNode(t1, new TreeNode(4)); // treeNodes = {1, 2, 4}

  // Test accessors
  printHeight(t1);
  printRoot(t1);
  printMin(t1);
  printMax(t1);
  printPredecessor(t1);
  printSuccessor(t1);

  // Test dupe node insertion
  t1->insertNode(t1, new TreeNode(1));
  printMin(t1);

  // Test copy constructor
  Tree* t2 = new Tree(*t1);
  delete (t1);
  printMin(t2);

  // Test assignment operator
  Tree t3 = *t2;
  delete (t2);
  printMin(&t3);

  // Test unbalanced node deletion
  t3.deleteNode(&t3, t3.findMin(t3.getRoot())); // treeNodes = {2, 4}
  printMin(&t3);
  printHeight(&t3); // TODO: Expand BST into self-balancing variation to address imbalance occurring here

  return 0;
}
#include <iostream>
#include "Tree.h"


void printHeight(Tree* tree) {
    std::cout << "Height : " << tree->getHeight() << std::endl;
}

void printMin(Tree* tree) {
    std::cout << "Min Key: " << tree->findMin(tree->getRoot())->key << std::endl;
}

void printMax(Tree* tree) {
    std::cout << "Max Key: " << tree->findMax(tree->getRoot())->key << std::endl;
}

int main() {
    Tree* t1 = new Tree();
    t1->insertNode(t1, new TreeNode(2));
    t1->insertNode(t1, new TreeNode(1));
    t1->insertNode(t1, new TreeNode(3));

    printMin(t1);
    printMax(t1);
    printHeight(t1);
    t1->insertNode(t1, new TreeNode(1));
    printHeight(t1);


    Tree t2 = *t1;
    delete (t1);

    t2.insertNode(&t2, new TreeNode(5));
    printMax(&t2);
    printHeight(&t2);

    return 0;
}
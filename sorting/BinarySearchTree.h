#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"

class BinarySearchTree
{
private:
    nodePtr root;
    void transplant(BinarySearchTree T, nodePtr u, nodePtr v);
public:


    BinarySearchTree();
    Node* getRoot();
    void setRoot(nodePtr x);
    void inorderTreeWalk(nodePtr x);
    void treeInsert(BinarySearchTree &T, nodePtr z);
    void treeDelete(BinarySearchTree &T, nodePtr z);
    Node* treeSearch(nodePtr x, int k);
    Node* iterativeTreeSearch(nodePtr x ,int k);
    Node* treeMinimum(nodePtr x);
    Node* treeMaximum(nodePtr x);
    Node* treeSucessor(nodePtr x);
    Node* treePredecessor(nodePtr x);
};

typedef class BinarySearchTree bst;

#endif
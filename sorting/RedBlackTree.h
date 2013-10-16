#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"

class RedBlackTree
{
private: 
    rbPtr root;
    void setRoot(rbPtr x);
    void rbTransplant(RedBlackTree &T, rbPtr u, rbPtr v);
    void rbDeleteFixup(RedBlackTree &T, rbPtr x);
    rbPtr treeMinimum(rbPtr x);
    rbPtr treeMaximum(rbPtr x);
    void inorderTreeWalk(rbPtr x);
    void RbInsertFixup(RedBlackTree &T, rbPtr z);
    void leftRotate(RedBlackTree &T, rbPtr z);
    void rightRotate(RedBlackTree &T, rbPtr z);

public:
    static const rbPtr nil;
    RedBlackTree();
    rbPtr getRoot();
    void inorderTreeWalk();
    void RbInsert(RedBlackTree &T, rbPtr z);
    void rbDelete(RedBlackTree &T, rbPtr z);
    rbPtr treeSearch(rbPtr x, int k);
    rbPtr iterativeTreeSearch(rbPtr x, int k);
    rbPtr treeSuccessor(rbPtr x);
    rbPtr treePredecessor(rbPtr x); 
    
};

typedef class RedBlackTree rbt;
#endif
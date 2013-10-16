#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"

class RedBlackTree
{
private: 
    rbPtr root;

public:
    static const rbPtr nil;
    RedBlackTree();
    void setRoot(rbPtr x);
    void leftRotate(RedBlackTree &T, rbPtr x);
};

const rbPtr RedBlackTree::nil = new RBNode(NULL, BLACK);

typedef class RedBlackTree rbt;
#endif
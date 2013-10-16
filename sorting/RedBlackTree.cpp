#include <iostream>
#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree()
{

}

void RedBlackTree::setRoot(rbPtr x)
{
    root = x;
}

void RedBlackTree::leftRotate(rbt &T, rbPtr x)
{
    rbPtr y = x->right;
    x->right = y->left;
    if (y->left != T.nil)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == T.nil)
    {
        T.setRoot(y);
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
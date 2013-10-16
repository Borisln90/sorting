#include <iostream>
#include "RedBlackTree.h"

using namespace std;

const rbPtr RedBlackTree::nil = new RBNode(NULL, BLACK);

RedBlackTree::RedBlackTree()
{
    root = nil;
}

rbPtr RedBlackTree::getRoot()
{
    return root;
}

void RedBlackTree::inorderTreeWalk()
{
    inorderTreeWalk(root);
}

void RedBlackTree::inorderTreeWalk(rbPtr x)
{
    if (x != nil)
    {
        inorderTreeWalk(x->left);
        cout << x->key << " ";
        inorderTreeWalk(x->right);
    }
}

rbPtr RedBlackTree::treeSearch(rbPtr x, int k)
{
    if (x == nil || k == x->key)
    {
        return x;
    }
    if (k < x->key)
    {
        return treeSearch(x->left, k);
    }
    else
    {
        return treeSearch(x->right, k);
    }
}

rbPtr RedBlackTree::iterativeTreeSearch(rbPtr x, int k)
{
    rbPtr t = x;
    while (t != NULL && k != t->key)
    {
        if (k < t->key)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    return t;
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

void RedBlackTree::rightRotate(rbt &T, rbPtr x)
{
    rbPtr y = x->left;
    x->left = y->right;
    if (y->right != T.nil)
    {
        y->right->parent = x;
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
    y->right = x;
    x->parent = y;
}

void RedBlackTree::RbInsert(rbt &T, rbPtr z)
{
    rbPtr y = T.nil;
    rbPtr x = T.getRoot();
    while (x != T.nil)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == T.nil)
    {
        T.setRoot(z);
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    z->left = T.nil;
    z->right = T.nil;
    z->color = RED;
    RbInsertFixup(T, z);
}

void RedBlackTree::RbInsertFixup(rbt &T, rbPtr z)
{
    rbPtr y;
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else 
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(T, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(T, z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(T, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(T, z->parent->parent);
            }
        }
    }
    T.getRoot()->color = BLACK;
}

void RedBlackTree::rbTransplant(rbt &T, rbPtr u, rbPtr v)
{
    if (u->parent == T.nil)
    {
        T.setRoot(v);
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedBlackTree::rbDelete(RedBlackTree &T, rbPtr z)
{
    rbPtr y = z;
    rbPtr x;
    int yOriginalColor = y->color;
    if (z->left == T.nil)
    {
        x = z->right;
        rbTransplant(T, z, z->right);
    }
    else if (z->right == T.nil)
    {
        x = z->left;
        rbTransplant(T, z, z->left);
    }
    else
    {
        y = treeMinimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            rbTransplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOriginalColor == BLACK)
    {
        rbDeleteFixup(T, x);
    }
}

void RedBlackTree::rbDeleteFixup(rbt &T, rbPtr x)
{
    rbPtr w;
    while (x != T.getRoot() && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            w = x->parent->right;
            if (w->color == RED)
            {
                w->color == BLACK;
                x->parent->color = RED;
                leftRotate(T, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else 
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(T, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(T, x->parent);
                x = T.getRoot();
            }
        }
        else
        {
            w = x->parent->left;
            if (w->color == RED)
            {
                w->color == BLACK;
                x->parent->color = RED;
                rightRotate(T, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(T, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(T, x->parent);
                x = T.getRoot();
            }
        }
    }
    x->color = BLACK;
}

rbPtr RedBlackTree::treeMinimum(rbPtr x)
{
    rbPtr t = x;
    while (t->left != nil)
    {
        t = t->left;
    }
    return t;
}

rbPtr RedBlackTree::treeMaximum(rbPtr x)
{
    rbPtr t = x;
    while (t->right != nil)
    {
        t = t->right;
    }
    return t;
}

rbPtr RedBlackTree::treeSuccessor(rbPtr x)
{
    if (x->right != nil)
    {
        return treeMinimum(x->right);
    }
    rbPtr z = x;
    rbPtr y = x->parent;
    while (y != nil && z == y->right)
    {
        z = y;
        y = y->parent;
    }
    return y;
}

rbPtr RedBlackTree::treePredecessor(rbPtr x)
{
    if (x->left != nil)
    {
        return treeMaximum(x->left);
    }
    rbPtr z = x;
    rbPtr y = x->parent;
    while (y != nil && z == y->left)
    {
        z = y;
        y = y->parent;
    }
    return y;
}

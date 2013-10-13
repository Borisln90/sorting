#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::transplant(bst T, nodePtr u, nodePtr v)
{
    if (u->parent == NULL)
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
    if (v != NULL)
    {
        v->parent = u->parent;
    }
}

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

Node* BinarySearchTree::getRoot()
{
    return root;
}

void BinarySearchTree::setRoot(nodePtr x)
{
    root = x;
}

void BinarySearchTree::inorderTreeWalk(nodePtr x)
{
    if (x != NULL)
    {
        inorderTreeWalk(x->left);
        cout << x->key << " ";
        inorderTreeWalk(x->right);
    }
}

void BinarySearchTree::treeInsert(bst &T, nodePtr z)
{
    nodePtr y = NULL;
    nodePtr x = T.getRoot();
    while (x != NULL)
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
    if (y == NULL)
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
}

void BinarySearchTree::treeDelete(bst &T, nodePtr z)
{
    nodePtr y;
    if (z->left == NULL)
    {
        transplant(T, z, z->right);
    }
    else if (z->right == NULL)
    {
        transplant(T, z, z->left);
    }
    else
    {
        y = treeMinimum(z->right);
        if (y->parent != z)
        {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

Node* BinarySearchTree::treeSearch(nodePtr x, int k)
{
    if (x == NULL || k == x->key)
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

Node* BinarySearchTree::iterativeTreeSearch(nodePtr x, int k)
{
    Node* t = x;
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

Node* BinarySearchTree::treeMinimum(nodePtr x)
{
    Node* t = x;
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t;
}

Node* BinarySearchTree::treeMaximum(nodePtr x)
{
    Node * t = x;
    while (t->right != NULL)
    {
        t = t->right;
    }
    return t;
}

Node* BinarySearchTree::treeSucessor(nodePtr x)
{
    if (x->right != NULL)
    {
        return treeMinimum(x->right);
    }
    nodePtr z = x;
    nodePtr y = x->parent;
    while (y != NULL && z == y->right)
    {
        z = y;
        y = y->parent;
    }
    return y;
}

Node* BinarySearchTree::treePredecessor(nodePtr x)
{
    if (x->left != NULL)
    {
        return treeMaximum(x->left);
    }
    nodePtr z = x;
    nodePtr y = x->parent;
    while (y != NULL && z == y->left)
    {
        z = y;
        y = y->parent;
    }
    return y;
}
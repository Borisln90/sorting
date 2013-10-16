#ifndef NODE_H
#define NODE_H

enum Color
{
    RED = 1,
    BLACK = 2

};

struct Node
    {
        Node* left;
        Node* right;
        Node* parent;
        int key;
        Node(int value)
        {
            left = NULL;
            right = NULL;
            key = value;
        }
    };

typedef struct Node* nodePtr;

struct RBNode
{
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    int key;
    int color;
    RBNode() {}
    RBNode(int value, int c)
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        key = value;
        color = c;
    }
};

typedef struct RBNode* rbPtr;

#endif
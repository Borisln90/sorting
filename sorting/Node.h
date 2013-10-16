#ifndef NODE_H
#define NODE_H

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

#endif
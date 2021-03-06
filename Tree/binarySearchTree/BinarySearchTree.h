#ifndef _BINARYSEARCHTREE_
#define _BINARYSEARCHTREE_

/// node Structure
struct Node {
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree {

    Node *root;

public:
    BinarySearchTree();
    Node *createNewNode(int);
    void insertNewNode(int);
    Node *insertNewNodeHelper(Node *, Node *);
    void insertNewNodeIte(int);
    void deleteNode(int);
    Node *deleteNodeHelper(Node *, int);
    Node *getSuccessor(Node *);
    bool searchNode(int);
    void printInorder();
};


#endif
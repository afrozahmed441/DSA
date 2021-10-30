#include <iostream>
#include <stack>
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

Node *BinarySearchTree::createNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 return newNode;
}

void BinarySearchTree::insertNewNode(int data) {
    Node *newNode = createNewNode(data);
    root = insertNewNodeHelper(root, newNode);
}

Node *BinarySearchTree::insertNewNodeHelper(Node *root, Node *newNode) {
    if(root == NULL) return newNode;    
    else if(root->data < newNode->data) root->right = insertNewNodeHelper(root->right, newNode);
    else root->left = insertNewNodeHelper(root->left, newNode);
 return root;
}

void BinarySearchTree::insertNewNodeIte(int data) {
    Node *newNode = createNewNode(data);
    if(root == NULL) root = newNode;

    Node *par = NULL;
    Node *cur = root;
    while(cur != NULL) {
        par = cur;
        if(cur->data > data) cur = cur->left;
        else if(cur->data < data) cur = cur->right;
        else return;
    }

    /// this condition is taken care at start, so no need but still i like to metion :)
    if(par == NULL) return;
    else if(par->data > data) par->left = newNode;
    else par->right = newNode;
}

bool BinarySearchTree::searchNode(int data) {
    Node *temp = root;
    while(temp != NULL) {
        if(temp->data == data) return true;
        else if(temp->data < data) temp = temp->right;
        else temp = temp->left;
    }
  return false;
}

void BinarySearchTree::printInorder() {
    if(root == NULL) return;
    stack<Node *> s;
    Node *cur = root;
    while(cur != NULL || !s.empty()) {
        while(cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}
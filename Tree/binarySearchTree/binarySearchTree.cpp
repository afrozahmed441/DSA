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

void BinarySearchTree::deleteNode(int data) {
    root = deleteNodeHelper(root, data);
}

Node *BinarySearchTree::getSuccessor(Node *root) {
    root = root->right;
    while(root != NULL && root->left != NULL) root = root->left;
    return root;
}

Node *BinarySearchTree::deleteNodeHelper(Node *root, int data) {
    if(root == NULL) return root;
    else if(root->data > data) root->left = deleteNodeHelper(root->left, data);
    else if(root->data < data) root->right = deleteNodeHelper(root->right, data);
    else {
        if(root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp; 
        }
        else {
            Node *suc = getSuccessor(root);
            root->data = suc->data;
            root->right = deleteNodeHelper(root->right, suc->data);
        }
    }
    return root;
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
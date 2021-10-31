#include <iostream>
using namespace std;

/*

- Problem   : Given a binary search tree and data find the data in the binary search tree if not present return the floor and ceil of the data

- input     : root of binary search tree and data
- output    : data or floor and ceil of the data

*/

/// structure of the Node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

//// ------------------------- Main Logic -----------------------------------
//// data node or floor node for given data 
Node *floorBST(Node *root, int data) {
    Node *res = NULL;
    /// if root is NULL return NULL
    if(root == NULL) return res;
    Node *cur = root;
    /// iterate through BST
    while(cur != NULL) {
        /// if the data is found in the BST return the node
        if(cur->data == data) res = cur;
        /// if the data is less than root data go to left sub tree
        else if(cur->data > data) cur = cur->left;
        /// if the data is greater than than the root data
        /// store the root nodes as floor 
        /// move to right sub tree
        else {
            res = cur;
            cur = cur->right;
        }
    }
 return res;
}

/// ceil 
Node *ceilBST(Node *root, int data) {
    Node *res = NULL;
    /// if root is NULL return NULL
    if(root == NULL) return res;
    /// iterate through BST 
    Node *cur = root;
    while(cur != NULL) {
        /// if the data node is found in BST
        if(cur->data == data) res = cur;
        /// if the data node is greater than the cur node
        /// move to right sub tree
        else if(cur->data < data) cur = cur->right;
        /// if the data node is smaller than the cur node
        /// store the cur node as ceil node
        /// move to left sub tree
        else {
            res = cur;
            cur = cur->left;
        }
    }
    return res;
}

int main() {

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);

    int data = 14;
    cout << "Floor in BST : " << ((floorBST(root, data) != NULL) ? floorBST(root, data)->data : -1) << endl;
    cout << "Ceil in BST : " << ((ceilBST(root, data) != NULL) ? ceilBST(root, data)->data : -1) << endl;
    cout << endl;

 return 0;
}
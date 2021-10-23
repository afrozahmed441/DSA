#include <iostream>
using namespace std;

/// Tree data Structure is a non linear Data Structure
/// Data in the tree data structure is arranged in hierarchial fashion

/// Structure of a node in the binary Tree
/// A node in the binary tree has data field, left child field and right child field
/// In binary Tree each node has at-most two childern 

/// Some Applications of Tree Data Structures
/// To represent Hierarchial data
/// Floder Structure 
/// XML/HTML content in DOM
/// In OOPs
/// Binary Search Tree 
/// Binary Heap
// B and B+ Trees 
/// Spanning Trees
/// Parse tree
/// Suffix Tree 
/// Binary Indexed Tree

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int main() {

    /// Typicall implmenetation of Binary Tree 
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /// printing nodes data
    cout << "ROOT : " << root->data << endl;
    cout << "LEFT : " << root->left->data << endl;
    cout << "RIGTH : " << root->right->data << endl;    

 return 0;
}
#include <iostream>
using namespace std;

/*

- Problem   : Given a binary tree, find the diameter of the binary tree (diameter is the number of nodes on the longest path between two leaf nodes)

- input     : root of the binary tree
- output    : diameter of the binary tree

*/

/// structure of the node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

//// -------------------------------- Main Logic ---------------------------------
/// #Method - 1
/// To calculate the left subtree height 
/// To calculate the right subtree height 
/// To calculate the height of the root node
/// And take max of three values 
/// Time Complexicty : O(N^2), where N is number of nodes in the binary tree

/// height recersive function
int height(Node *root) {
    if(root == NULL) return 0;
    return (max(height(root->left), height(root->right))+1);
}

/// diameter 
int diameter(Node *root) {
    if(root == NULL) return 0;

    int rootDiameter = 1+height(root->left)+height(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(rootDiameter, max(leftDiameter, rightDiameter));

}

/// Todo Efficient Solution

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Test Case 1 : " << endl;
    cout << "Diameter : " << diameter(root);
    cout << endl;

 return 0;
}
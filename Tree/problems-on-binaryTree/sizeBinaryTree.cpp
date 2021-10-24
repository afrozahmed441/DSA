#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   :  Given Binary Tree, find the size of the binary tree (size of binary tree is number of nodes in the binary tree, leaf node has size 1)

- input     : root node of the binary tree
- output    : size of binary tree

*/

/// structure of node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/// random tree generator function, for testing purpose
Node *createRandomBinaryTree(int n) {
    Node *root = new Node(1);
    int i = 1;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false && i < n) {
        Node *cur = q.front();
        q.pop();
        cur->left = new Node(++i);
        q.push(cur->left);
        cur->right = new Node(++i);
        q.push(cur->right);
    }
  return root;
}

//// -------------------------------- Main Logic -------------------------------
/// Recersive Solution

/// Time Complexcity  : O(N), where N is number of nodes 
/// Auxiliary Space   : O(H), where H is height of tree
int size(Node *root) {
    /// base case, if root is null return 0
    if(root == NULL) return 0;
    /// else recersively call for left sub tree and right sub tree and add one to the result and return to parent caller
    return (size(root->left)+size(root->right)+1);
}


int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "Size of Binary Tree : " << size(root) << endl;
    cout << endl;

    Node *root2 = createRandomBinaryTree(10);
    cout << "Size of Binary Tree : " << size(root2) << endl;
    cout << endl;

    Node *root3 = createRandomBinaryTree(5);
    cout << "Size of Binary Tree : " << size(root3) << endl;
    cout << endl;

 return 0;
}
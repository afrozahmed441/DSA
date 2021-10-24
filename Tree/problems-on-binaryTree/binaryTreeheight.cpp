#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   :  Given a Binary Tree, find the height of the binary tree

- input     : root node of the binary tree
- output    : height of the binary tree

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

/// ------------------------------- Main Logic ----------------------------------
/// recersive solution
/// Algo : 
/// 1. Base Case in the recersion is to return 0 when the root node is null
/// 2. We will be recersivly calling for left sub tree -> this will return height of left sub tree
/// 3. We will be recersivly calling for right sub tree -> this will return height of right sub tree
/// 4. Then we will be taking the max of right sub tree and left sub tree and adding one to it and return it to parent call.
/// 5. At lest it will return the height of the tree to the parent caller. 

/// Time Complexcity : O(N), where N is number of nodes 
/// Auxiliary Space  : O(H), where H is height of the binary tree
int height(Node *root) {
    /// root is NULL
    if(root == NULL) return 0;
    /// else 
    return (max(height(root->left), height(root->right))+1);

}


int main() {

    Node *root = createRandomBinaryTree(5);
    cout << "Height of Binary Tree is : " << height(root) << endl;
    cout << endl;

    Node *root2 = createRandomBinaryTree(1);
    cout << "Height of Binary Tree is : " << height(root2) << endl;
    cout << endl;

    Node *root3 = createRandomBinaryTree(3);
    cout << "Height of Binary Tree is : " << height(root3) << endl;
    cout << endl;

 return 0;
}
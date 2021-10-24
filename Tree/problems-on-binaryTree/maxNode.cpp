#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   : Given Binary Tree, Find the node with maximum value 

- input     : Root node of the binary tree
- ouput     : maximum node of the binary tree

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


//// -------------------------- Main Logic ------------------------------------
/// Recersive Algo

int maxNode(Node *root) {
    if(root == NULL) return INT_MIN;
    return max(root->data, max(maxNode(root->left), maxNode(root->right)));
}

int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "Max Node is : " << maxNode(root) << endl;
    cout << endl;

    Node *root2 = createRandomBinaryTree(5);
    cout << "Max Node is : " << maxNode(root2) << endl;
    cout << endl;

    Node *root3 = createRandomBinaryTree(10);
    cout << "Max Node is : " << maxNode(root3) << endl;
    cout << endl;

}
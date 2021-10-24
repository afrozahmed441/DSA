#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   : Given a Binary Tree, find the maximum width of the given binary tree

- input     : Root node of the binary tree
- output    : Maximum width of the binary tree

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

//// ---------------------------- Main Logic ----------------------------------
/// Algo :
/// Using Level Order Traversal 

int maxWidth(Node *root) {
    /// if root is null
    if(root == NULL) return -1;

    queue<Node *> que;
    que.push(root);
    int res = 0;
    while(!que.empty()) {
        int count = que.size();
        res = max(res, count);
        
        for(int i = 0; i < count; i++) {
            Node *cur = que.front();
            que.pop();
            if(cur->left != NULL) que.push(cur->left);
            if(cur->right != NULL) que.push(cur->right);
        }
    }
    return res;
}

int main() {
    Node *root = createRandomBinaryTree(7);
    cout << "Max Width : " << maxWidth(root) << endl;
    cout << endl;

    Node *root2 = createRandomBinaryTree(3);
    cout << "Max Width : " << maxWidth(root2) << endl;
    cout << endl;

    Node *root3 = createRandomBinaryTree(10);
    cout << "Max Width : " << maxWidth(root3) << endl;
    cout << endl;

 return 0;
}
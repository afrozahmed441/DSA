#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   :  Given a Binary Tree, print the left view of the binary tree

- input     : Root node of the binary tree
- ouput     : left view of binary tree

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

//// ------------------------------ Main Logic -----------------------------------
/// Recersive Algo:
/// We will use preorder traversal 
/// and we keep track of level visited using maxlevel variable 
/// if maxlevel is less than the current level then we print the node else we don't print the node

void leftView(Node *root, int level, int &maxLevel) {

    if(root == NULL) return;

    if(maxLevel < level) {
        cout << root->data << " ";
        maxLevel = level;
    }

    leftView(root->left, level+1, maxLevel);
    leftView(root->right, level+1, maxLevel);
}

void printLeftView(Node *root) {
    int maxLevel = 0;
    leftView(root, 1, maxLevel);
}

int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "Left View of Binary Tree : ";
    printLeftView(root);
    cout << endl;

    Node *root2 = createRandomBinaryTree(5);
    cout << "Left View of Binary Tree : ";
    printLeftView(root2);
    cout << endl;

 return 0;
}
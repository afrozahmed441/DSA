#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   :  Given Binary Tree and integer k, print all the nodes at k distance from the node

- input     : Root of the binary tree
- ouput     : nodes at k level 

NOTE : k >= 0 

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

/// -------------------------------- Main Logic ------------------------------
/// Recersive Algo:
/// 1. Base Case if the root is NULL, we return the function
/// 2. If k is 0 or reduced to zero then we print the data part of the node
/// 3. else we call recersivly the left sub tree and pass k-1 
/// 4. After Left sub tree reaches k == 0 then prints the nodes or root becomes NULL then also we return the function
/// 5. Then we call recersivly the right sub tree and pass k-1
/// 6. After Right Sub tree reaches k == 0 then prints the nodes or root becomes NULL the functions retuns

void printKDistNodes(Node *root, int k) {
    /// if root is null
    if(root == NULL) return;
    /// if k is 0 or reduced to zero
    if(k == 0) cout << root->data << " ";

    else {
        printKDistNodes(root->left, k-1);
        printKDistNodes(root->right, k-1);
    }

}

int main() {

    Node *root = createRandomBinaryTree(10);
    int k = 2;
    cout << "Nodes At level " << k << " are : ";
    printKDistNodes(root, k);
    cout << endl;

    Node *root2 = createRandomBinaryTree(10);
    int k2 = 1;
    cout << "Nodes At level " << k2 << " are : ";
    printKDistNodes(root2, k2);
    cout << endl;

 return 0;
}
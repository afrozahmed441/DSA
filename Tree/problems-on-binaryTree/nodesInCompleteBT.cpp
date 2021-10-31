#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*

Problem     : Given a complete binary tree, count number of nodes in it.

input       : root of the complete binary tree
output      : number of nodes

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


/// create a random tree
Node *createRandomBinaryTree(int n) {
    Node *root = new Node(1);
    int c = 1;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false && c < n) {
        Node *cur = q.front();
        q.pop();

        cur->left = new Node(++c);
        q.push(cur->left);
        cur->right = new Node(++c);
        q.push(cur->right);
    }
    return root;
}

/// ---------------------------------- Main Logic --------------------------------
/// Naive Solution 
/// Time Complexcity : O(N), where N is number of nodes
int countNodes(Node *root) {
    if(root == NULL) return 0;
    return (1+countNodes(root->left)+countNodes(root->right));
}

/// Efficient Solution : O(logn *logn)
/// Make use of property of the complete binary tree 
/// In complete binary tree there are sub trees which are perfect binary trees
/// In perfect binary tree there are exactly 2^h - 1 nodes (h is height)
int countNodesEff(Node *root) {
    int lh = 0;
    int rh = 0;
    Node *temp = root;
    while(temp != NULL) {
        lh++;
        temp = temp->left;
    }
    Node *t = root;
    while(t != NULL) {
        rh++;
        t = t->right;
    }

    if(lh == rh) return (pow(2, lh)-1);
    else return (1+countNodesEff(root->left)+countNodesEff(root->right));
}


int main() {

    Node *root = createRandomBinaryTree(5);
    cout << "---------------- Naive -------------" << endl;
    cout << "Number of Nodes : " << countNodes(root) << endl;
    cout << endl;

    cout << "--------------- Efficient -----------" << endl;
    cout << "Number of Nodes : " << countNodesEff(root) << endl;
    cout << endl;

 return 0;
}
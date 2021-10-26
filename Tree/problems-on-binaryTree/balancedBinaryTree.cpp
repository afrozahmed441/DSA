#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   :  Given a binary tree, check if it is balanced binary tree or not

- input     : root node of the binary 
- output    : true or false

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


///// --------------------------- Main Logic ----------------------------------

int height(Node *root) {
    if(root == NULL) return 0;
    return (max(height(root->left), height(root->right))+1);
}

/// Naive Solution 
/// Time Complexcity : O(N^2), where N is number of nodes in the binary tree
bool isBalanced(Node *root) {
    if(root == NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

/// Efficient Solution
/// Time Complexcity : O(N), where N is number of nodes in the binary tree
int isBalancedEff(Node *root) {
    if(root == NULL) return 0;
    int lh = isBalancedEff(root->left);
    if(lh == -1) return -1;
    int rh = isBalancedEff(root->right);
    if(rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;
    else return max(lh, rh)+1;
}

int main() {

    cout << "--------------------- Naive Solution --------------------------" << endl;
    cout << "Test Case 1 : " << endl;
    Node *root = createRandomBinaryTree(3);
    cout << "Is Balanced : " << isBalanced(root) << endl;
    cout << endl;

    cout << "Test Case 2 : " << endl;
    Node *root2 = createRandomBinaryTree(5);
    cout << "Is Balanced : " << isBalanced(root2) << endl;
    cout << endl;

    cout << "Test Case 3 : " << endl;
    Node *root3 = createRandomBinaryTree(10);
    cout << "Is Balanced : " << isBalanced(root3) << endl;
    cout << endl;

    cout << "---------------------- Efficient Solution ---------------------" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "Is Balanced : " << ((isBalancedEff(root) >= 0) ? 1 : 0) << endl;
    cout << endl;

    cout << "Test Case 2 : " << endl;
    cout << "Is Balanced : " << ((isBalancedEff(root2) >= 0) ? 1 : 0) << endl;
    cout << endl;

    cout << "Test Case 3 : " << endl;
    cout << "Is Balanced : " << ((isBalancedEff(root3) >= 0) ? 1 : 0) << endl;
    cout << endl;

  return 0;
}
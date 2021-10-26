#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   :  Given a Binary Tree, check it satisfies the children sum property, which is the value of parent node should be equal to sum of its children

- input     :  root of the binary tree
- output    :  true if the binary tree satisfy, else false

*/

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

////// ---------------------------------- Main Logic ------------------------------
//// Recersive Algo :
//// 1. if root is NULL,  return true
//// 2. if the node is leaf node, return true
///  3. else compute the sum of children of the root
///  4. and check if the sum is equal to root node if it is not equal return false,
///  5. else compute the same for left and right children recersively.
bool checkChildrenSumProp(Node *root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return true;

    int sum = 0;
    if(root->left != NULL) sum += root->left->data;
    if(root->right != NULL) sum += root->right->data; 

    return (root->data == sum && checkChildrenSumProp(root->left) && checkChildrenSumProp(root->right));

}

//// iterative solution using level order traversal
bool checkChildrenSumPropL(Node *root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()) {
        Node *cur = q.front();
        q.pop();

        int sum = 0;
        if(cur->left != NULL) {
            sum += cur->left->data;
            q.push(cur->left);
        }

        if(cur->right != NULL){
            sum += cur->right->data;
            q.push(cur->right);
        } 
        
        if((cur->left != NULL || cur->right != NULL) && sum != cur->data) return false;
        else continue;
    }
    return true;
}   

int main() {

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);

    cout << checkChildrenSumProp(root) << endl;
    cout << checkChildrenSumPropL(root) << endl;
  return 0;
}
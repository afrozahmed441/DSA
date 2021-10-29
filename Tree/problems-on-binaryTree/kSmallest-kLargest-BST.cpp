#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   : Given a Binary Search Tree find the k smallest element and k largest element in the Binary Search Tree

- input     : Root of the binary search tree
- output    : k-smallest and k-largest in the binary search tree

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

////////// ------------------------ Main Logic ---------------------------------
//// k-smallest Algo:
/// In Binary Search Tree, the left node is smaller than root node and right node is greater than root node.
/// The above property of Binary Search Tree  gives the sorted order of nodes when performed inorder traversal on any BST. I can use this property to figure the k-smallest and k-largest in BST.
int kSmallestNode(Node *root, int k) {
    if(root == NULL) return -1;
    stack<Node *> s;
    Node *cur = root;
    int c = 0;
    while(cur != NULL || !s.empty()) {
        while(cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        c++;
        if(c == k) return (cur->data);
        cur = cur->right;
    }
    return -1;
}

/// k-largest Algo:
/// I can reverse the inorder traversal from left root right to right root left to get the k largest elements from the BST.
int kLargestNode(Node *root, int k) {
    if(root == NULL) return -1;
    stack<Node *> s;
    Node *cur = root;
    int c = 0;
    while(cur != NULL || !s.empty()) {
        while(cur != NULL) {
            s.push(cur);
            cur = cur->right;
        }
        cur = s.top();
        s.pop();
        c++;
        if(c == k) return (cur->data);
        cur = cur->left;
    }
 return -1;
}


int main() {

    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(2);
    root->right->right->right = new Node(8);

    int k = 3;
    cout << k << "-Smallest Node in the BST : " << kSmallestNode(root, k) << endl; 
    cout << endl;
    cout << k << "-Largest Node in the BST : " << kLargestNode(root, k) << endl;
    cout << endl;
    

 return 0;
}
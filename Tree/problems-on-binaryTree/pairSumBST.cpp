#include <iostream>
#include <unordered_set>
using namespace std;

/*

- Problem   : Give a BST and a value, find if there exists a pair whose value is equall to given value

- input     : BST root, value (sum)
- output    : true or false
*/

/// node strcture 
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

//// -------------------------------- Main Logic ----------------------------------
//// #Method-1 
/// 1. Do inorder traversal of the binary search tree and store the values into a array
/// 2. Use two pointer approach to find the pair in the array.

/// #Method-2 Hashing
/// 1. Traverse the binary search tree in inorder 
/// 2. check if the current root value minus value is present in the hash table
/// 3. If present in the hash table then return true
/// 4. else insert the current root value into the hash table
/// 5. follow the above steps in recersion until we have visited all the nodes in the binary search tree

bool pairSumBST(Node *root, int sum, unordered_set<int> &s) {
    if(root==NULL) return false;
    if(pairSumBST(root->left, sum, s)) return true;
    if(s.find(sum-(root->data)) != s.end()) return true;
    else s.insert(root->data);
    return pairSumBST(root->right, sum, s);
}


int main() {

    Node *root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);

    cout << "Test Case 1 : " << endl;
    int sum = 33;
    unordered_set<int> s;

    cout << (pairSumBST(root, sum, s)?"True":"False") << endl;
    cout << endl;

 return 0;
}
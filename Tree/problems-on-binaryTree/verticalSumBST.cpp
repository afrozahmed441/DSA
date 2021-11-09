#include <iostream>
#include <map>
using namespace std;

/*

- Problem   :  Given a Binary Tree, Find the vertical sum of all the nodes in the binary tree

- input     :  root of binary Tree
- output    :  sum of all vertical node in the binary tree

- Example Test Cases

- o/i  :     1
           /  \
          2    3
        /  \ /  \
       4   5 6  7

- o/p : 4 2 12 3 7

*/

/// node structure
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

/// ---------------------- Main Logic --------------------------------------------
/// consider the horizontal distance between the nodes to perform vertical sum 
/// start the root at 0, if you move towords left then perfrom -1 to current horizontal distance
/// if you move towords right then perform +1 to current horizontal distance

/// Algo:
/// 1. Create a empty map to keep track of vertical sum of the nodes at particular horizontal distance
/// 2. perform inorder and while doing inorder keep track of horizontal distance of nodes 
/// 3. according to the horizontal distance perform the sum of nodes at a particular horizontal distance.

void verticalSumBT(Node *root, int hd, map<int, int> &m) {
    if(root == NULL) return;
    verticalSumBT(root->left, hd-1, m);
    m[hd] += root->data;
    verticalSumBT(root->right, hd+1, m);
}

void verticalSum(Node *root) {
    map<int, int> m;
    verticalSumBT(root, 0, m);
    for(auto sum : m) {
        cout << sum.second << " ";
    } 
    cout << endl;
}

/// TODO try to slove without map

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Test Case 1 : " << endl;
    verticalSum(root);
 
 return 0;
}
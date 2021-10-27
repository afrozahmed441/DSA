#include <iostream>
#include <queue>
using namespace std;

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


//////// -------------------------- Main Logic -----------------------------------

//// recersive solution
//// range based solution, i will be comparing each node with a particular range if the node is in the range then it is a BST, else not BST
bool isBSTRec(Node *root, int min, int max) {
    if(root == NULL) return true;
    
    return((root->data > min && root->data < max) 
            && isBSTRec(root->left, min, root->data) 
            && isBSTRec(root->right, root->data, max));
}

/// using inorder traversal (recersive)
/// in BST if we do inorder traversal then the result is in form of sorted nodes 
bool isBSTIn(Node *root, int &prev) {
    if(root == NULL) return true;
    if(!isBSTIn(root->left, prev)) return false;
    if(root->data <= prev) return false;
    prev = root->data;
    return isBSTIn(root->right, prev);
}

int main() {

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);

    cout << "--------------- using recersive solution --------------------" << endl;
    cout << "Test Case 1 : " << endl;
    cout << isBSTRec(root, LONG_MIN, LONG_MAX) << endl;

    cout << "--------------- using inorder solution --------------------" << endl;
    cout << "Test Case 1 : " << endl;
    int prev = LONG_MIN;
    cout << isBSTIn(root, prev) << endl;


 return 0;
}
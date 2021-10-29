#include <iostream>
using namespace std;

/*

-  Problem  :  Given inorder and preorder traversal of a binary tree, build binary tree from preorder and inorder

-  input    : inorder and preorder traversal of a binary tree
-  output   : root of the constructed binary tree.

*/

/// strcuture of the node
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

//// To test the code
void preorder(Node *root) {
    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void printPreOrder(int in[], int n) {
    for(int i = 0; i < n; i++) cout << in[i] << " ";
    cout << endl;
}

//// ------------------------------ Main Logic ------------------------------------
Node *buildBinaryTree(int in[], int pre[], int is, int ie, int &preInd) {
    /// if three is no Left or right child return NULL
    /// when the start index of inorder is greater than the end index then return NULL
    if(is > ie) return NULL;

    /// make node of root data (use preorder)
    Node *root = new Node(pre[preInd++]);

    /// find the index of the root node in the inorder 
    /// and the nodes all left to the root node are part of left sub tree
    /// and the nodes all right to the root node are part of right sub tree
    int inInd = 0;
    for(int i = is; i <=ie; i++) {
        if(in[i] == root->data) {
            inInd = i;
            break;
        }
    }

    /// recersively call the buildBinaryTree with the left nodes and right nodes
    root->left = buildBinaryTree(in, pre, is, inInd-1, preInd);
    root->right = buildBinaryTree(in, pre, inInd+1, ie, preInd);

 /// after processing the left and right sub trees return the root of the binary tree
 return root;
}

int main() {

    int in[] {4, 2, 5, 1, 6, 3, 7};
    int pre[] {1, 2, 4, 5, 3, 6, 7};
    int is {0};
    int ie {6};
    int preInd {0};
    int size {7};

    Node *root = buildBinaryTree(in, pre, is, ie, preInd);
    cout << "Actual PreOrder : ";
    printPreOrder(pre, size);
    cout << "Build Binary Tree PreOrder : ";
    preorder(root);
    cout << endl;
}
#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   : Given a binary Tree, Print the Postorder traversal of the binary tree

- input     : root of the binary tree
- output    : postorder traversal of the tree

- Example Test Cases:
  
  i/o:
        1
    2      3
  
  o/p: 2 3 1

  i/o :
        1
    2       3
 4    5   6    7

  o/p : 4 5 2 6 7 3 1

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

//// --------------------------- Main Logic ------------------------------------
//// Recersive PostOrder Traversal 
/// Travel to the left sub tree and print the left sub tree recersivly
/// Travel to the right sub tree and print the right sub tree recersivly
/// Travel to the root, print the root

/// Time Complexcity : O(N), where N is number of nodes in the binary Tree
/// Auxiliary Space  : O(H), where H is hight of the binary Tree
void postorder(Node *root) {
    if(root == NULL) return;
    else {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

/// main function 
int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "===================== Postorder Traversal =======================" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    Node *root2 = createRandomBinaryTree(7);
    cout << "Test Case 2 : " << endl;
    cout << "Postorder : ";
    postorder(root2);
    cout << endl;


 return 0;
}
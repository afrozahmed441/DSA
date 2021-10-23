#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*

- Problem   :  Given a Binary Tree Print the inorder Traversal of the given binary Tree

- input     : Root of the binary Tree
- output    : Inorder Traversal of binary tree

- Example Test Cases:

  i/o:
        1
    2      3

  o/p:  2 1 3

  i/o:
        1
    2       3
 4    5   6    7

 o/p:  4 2 5 1 6 3 7


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
//// Iterative Inordre Traversal 
/// Create a empty stack 
/// push the root node into the stack 
/// we push the curNode left into the stack until the left node is NULL
/// then we pop the top of the stack and print the data of the node
/// and make the cur node as cur->right 
/// repeat the above steps until the cur is notl NULL or stack is not empty 

/// Time Complexcity : O(N), where N is number of nodes in the binary Tree
/// Auxiliary Space  : O(H), where H is hight of the binary Tree
void inorder(Node *root) {
    if(root == NULL) return;
    stack<Node *> s;
    Node *cur = root;
    while(cur != NULL || !s.empty()) {
        while(cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}

/// main function 
int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "===================== Inorder Traversal =======================" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "inorder : ";
    inorder(root);
    cout << endl;

    Node *root2 = createRandomBinaryTree(7);
    cout << "Test Case 2 : " << endl;
    cout << "inorder : ";
    inorder(root2);
    cout << endl;


 return 0;
}
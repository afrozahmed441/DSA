#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*

- Problem   : Given a binary Tree, Print the Preorder traversal of the binary tree

- input     : root of the binary tree
- output    : Preorder traversal of the tree

- Example Test Cases:
  
  i/o:
        1
    2      3
  
  o/p: 1 2 3

  i/o :
        1
    2       3
 4    5   6    7

  o/p : 1 2 4 5 3 6 7

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
//// Iterative Preorder Traversal 
/// Algo:
/// Create a empty Stack 
/// Take a variable of type node, cur and point it to root
/// while cur is not NULL, we print the data of the cur and check if there is a right child 
/// if right child it not NULL then push the right child into the stack
/// and move the cur to cur->left
/// if cur is NULL and stack is not empty then pop the top element and assign it as cur
/// repeat the process until the cur is not NULL or stack is not empty


/// Time Complexcity : O(N), where N is number of nodes in the binary Tree
/// Auxiliary Space  : O(H), where H is hight of the binary Tree
void preorder(Node *root) {
    stack<Node *> s;
    Node *cur = root;
    while(cur != NULL || !s.empty()) {
        while(cur != NULL) {
            cout << cur->data << " ";
            if(cur->right != NULL) s.push(cur->right);
            cur = cur->left; 
        }
        if(!s.empty()) {
            cur = s.top();
            s.pop();
        }
    }
}

/// main function 
int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "===================== Perorder Traversal =======================" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "Perorder : ";
    preorder(root);
    cout << endl;

    Node *root2 = createRandomBinaryTree(7);
    cout << "Test Case 2 : " << endl;
    cout << "Perorder : ";
    preorder(root2);
    cout << endl;


 return 0;
}
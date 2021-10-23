#include <iostream>
#include <queue>
#include <stack>
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
//// Iterative PostOrder Traversal 
/// Algo:
/// Create two empty stack one to store the addreess of nodes and another to store the output
/// push the root node  into the stack.
/// while stack is not empty 
/// pop the elemenets from the stack 
/// push the data of the current popped element into the output stack.
/// and push the left child of current popped node into the stack , if it is not NULL
/// and push the right child of current popped node into the stack, if it is not NULL
/// in the same sequence (sequence is important here)
/// repeat the steps until stack(the one which stores nodes) is empty
/// and now pop the elements from output stack and print them, until stack is empty

/// Time Complexcity : O(N), where N is number of nodes in the binary Tree
/// Auxiliary Space  : O(H), where H is hight of the binary Tree
void postorder(Node *root) {
    stack<Node *> s;
    stack<int> output; 
    s.push(root);
    while(!s.empty()) {
        Node *cur = s.top();
        s.pop();
        output.push(cur->data);
        if(cur->left != NULL) s.push(cur->left);
        if(cur->right != NULL) s.push(cur->right);
    }

    while(!output.empty()){
        cout << output.top() << " ";
        output.pop();
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
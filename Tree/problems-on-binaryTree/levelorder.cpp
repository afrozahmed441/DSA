#include <iostream>
#include <queue>
using namespace std;

/*

- Problem   : Given a binary Tree, Print the LevelOrder traversal of the binary tree

- input     : root of the binary tree
- output    : LevelOrder traversal of the tree

- Example Test Cases:
  
  i/o:
        1
    2      3
  
  o/p: 1 2 3

  i/o :
        1
    2       3
 4    5   6    7

  o/p : 1 2 3 4 5 6 7

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
/// Level Order Traversal
/// Algo:
/// we create a empty queue and push the root of the binary tree into queue
/// while queue is not empty we pop the elements one by one from the queue
/// print the data of the element 
/// check if the left child is NULL or not NULL, if not NULL then we push the left child node address into the queue
/// check if the right child is NULL or not NULL, if not NULL then we push the right child node address into the queue
/// if queue becomes empty then we stop the process.

/// Time Complexcity : O(N), where N is number of nodes in the binary Tree
/// Auxiliary Space  : O(B), where B is breadth of the binary Tree
void levelOrder(Node *root) {
    if(root == NULL) return;
    queue<Node *> que;
    que.push(root);
    while(!que.empty()) {
        Node *cur = que.front();
        que.pop();
        cout << cur->data << " ";
        if(cur->left != NULL) que.push(cur->left);
        if(cur->right != NULL) que.push(cur->right);
    }
}

/// main function 
int main() {

    Node *root = createRandomBinaryTree(3);
    cout << "===================== Level Order Traversal =======================" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "Level Order : ";
    levelOrder(root);
    cout << endl;

    Node *root2 = createRandomBinaryTree(7);
    cout << "Test Case 2 : " << endl;
    cout << "Level Order : ";
    levelOrder(root2);
    cout << endl;


 return 0;
}
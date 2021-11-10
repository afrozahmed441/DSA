#include <iostream>
#include <queue>
#include <map>
using namespace std;

/*

- Problem   : Given a binary Tree, perform vertical traversal of nodes in the binary tree

- input     : root node of binary tree
- output    : vertical traversal of binary tree

- Example Test Cases : 

- o/i   :   1 
          /  \
         2    3
       /  \ /  \
      4   5 6  7

- o/p : 4 
        2
        1 5 6
        3 
        7
*/

/// Node Strcture 
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

//// ----------------------------- Main Logic -------------------------------------
/// Algo : 
/// 1. Consider the horizontal distances between nodes 
/// 2. Create a empty map, where key is horizontal distance and value is an array of elements (or vector)
/// 3. Do level order traversal of the binary Tree 
/// 4. Consider both horizontal distance and node and insert into queue will doing level order traversl 
/// 5. while dequeuing and insert other children of that node, insert the node data into map with the horizontal distance as key 
/// 6. Repeat until level order traversl is done. 
/// 7. Print the vector elements in the values of map at each horizontal distance.

void verticalTraversal(Node *root) {

    if(root == NULL) return;
    /// create a queue 
    queue<pair<int, Node*>> q;
    /// create a map
    map<int, vector<int>> m;
    /// perform level order traversal
    q.push({0, root});
    while(!q.empty()) {
        Node *cur = q.front().second;
        int hd = q.front().first;
        m[hd].push_back(cur->data);
        q.pop();
        /// check for left child
        if(cur->left != NULL) q.push({hd-1, cur->left});
        /// check for right child
        if(cur->right != NULL) q.push({hd+1, cur->right});
    }

    for(auto p : m) {
        for(auto ele : p.second) {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Test Case 1 : " << endl;
    verticalTraversal(root);

 return 0;
}
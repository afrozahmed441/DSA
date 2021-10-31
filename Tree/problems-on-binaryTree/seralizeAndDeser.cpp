#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

- Problem   : Given a binary tree convert it into an array (serialize) and give a array convert into binary tree (deserialize)

- input     : root of the binary tree, vector 
- output    : binary tree in array representation, binary tree

*/


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

/// create a random tree
Node *createRandomBinaryTree(int n) {
    Node *root = new Node(1);
    int c = 1;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false && c < n) {
        Node *cur = q.front();
        q.pop();

        cur->left = new Node(++c);
        q.push(cur->left);
        cur->right = new Node(++c);
        q.push(cur->right);
    }
    return root;
}

//// helper function for printing the nodes data in the array
void print(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}

/// helper function for printing inorder 
void printInorder(Node *root) {
    if(root != NULL) {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

////// ------------------------------ Main Logic ---------------------------
/// we can use any traversal to serialize the binary tree 
/// i am using preorder traversal to serialize the binry tree
/// NOTE : we need to use the same traversal while we deserialize it.
void serialize(Node *root, vector<int> &arr) {
    if(root == NULL) {
        //// assume that -1 is not in the data. And the -1 indicates the end of the node (leaf nodes) 
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

//// Derserializer 
Node *deSerialize(vector<int> &arr, int &ind) {
    /// if we reach the end of the array
    if(ind == arr.size()) return NULL;
    /// if it is a leaf node
    int val = arr[ind++];
    if(val == -1) return NULL;
    /// create a node with current data
    Node *root = new Node(val);
    /// recersively build left sub tree
    root->left = deSerialize(arr, ind);
    /// recersively build right sub tree
    root->right = deSerialize(arr, ind);

 return root;
}


int main() {

    Node *root = createRandomBinaryTree(5);
    vector<int> arr;
    serialize(root, arr);
    cout << "------------- Serialize --------------------" << endl;
    print(arr);
    cout << endl;

    cout << "-------------- Deserialize --------------------" << endl;
    cout << "Inorder Before : ";
    printInorder(root);
    cout << endl;
    cout << "Inorder After : ";
    int ind = 0;
    Node *dRoot = deSerialize(arr, ind);
    printInorder(dRoot);
    cout << endl;

 return 0;
}
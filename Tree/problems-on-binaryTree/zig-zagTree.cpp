#include <iostream>
#include <queue>
#include <stack>
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

//////-------------------------- Main Logic ------------------------------------
/// using level order traversal 
void zigZagLevel(Node *root) {
    if(root == NULL) return;
    bool reverse = false;
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    while(!q.empty()){
        
        int c = q.size();
        for(int i = 0; i < c; i++) {
            Node *cur = q.front();
            q.pop();

            if(reverse) s.push(cur);
            else cout << cur->data << " ";

            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
        
        if(reverse) {
            while(!s.empty()) {
                cout << s.top()->data << " ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}

//// using two stack
void zigZagStacks(Node *root) {
    if(root == NULL) return;
    stack<Node *> curLevel;
    stack<Node *> nextLevel;
    curLevel.push(root);
    while(!curLevel.empty() || !nextLevel.empty()) {
        while(!curLevel.empty()) {
            Node *cur = curLevel.top();
            curLevel.pop();

            cout << cur->data << " ";
            if(cur->left != NULL) nextLevel.push(cur->left);
            if(cur->right != NULL) nextLevel.push(cur->right);
        }
        
        cout << endl;

        while(!nextLevel.empty()) {
            Node *cur = nextLevel.top();
            nextLevel.pop();

            cout << cur->data << " ";
            if(cur->right != NULL) curLevel.push(cur->right);
            if(cur->left != NULL) curLevel.push(cur->left);
        }

        cout << endl;

    }

}


int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "-------------- Using level order ------------------------------ " << endl;
    zigZagLevel(root);
    cout << endl;

    cout << "-------------- Using Two Stacks ------------------------------ " << endl;
    zigZagStacks(root);
    cout << endl;

 return 0;
}
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {

    BinarySearchTree bst;
    bst.insertNewNode(10);
    bst.insertNewNode(5);
    bst.insertNewNode(11);
    bst.insertNewNode(3);
    bst.insertNewNode(1);
    bst.insertNewNode(15);

    cout << "Print Inorder of BST : ";
    bst.printInorder();
    cout << endl;

    bst.insertNewNodeIte(16);
    cout << "Print Inorder of BST : ";
    bst.printInorder();
    cout << endl;

    int data = 5;
    cout << "Find Node " << data << " : " << bst.searchNode(data); 
    cout << endl;
    
 return 0;
}
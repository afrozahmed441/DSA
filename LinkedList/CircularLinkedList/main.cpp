#include <iostream>
#include "circularLinkedList.h"
using namespace std;

int main(){
    CircularLinkedList cl;
    cl.insertAtBegin(1);
    cl.insertAtEnd(2);
    cl.insertAtEnd(3);
    cl.insertAtEnd(4);
    cl.insertAtEnd(5);
    cout << "[Circular Linked List] : ";
    cl.printCList();
    cout << "[Deleted Node] : " << cl.deleteAtBegin() << endl;
    cout << "[Deleted Node] : " << cl.deleteAtEnd() << endl;
    cout << "[Circular Linked List] : ";
    cl.printCList();
    cout << "[Deleted Node] : " << cl.deleteAtEnd() << endl;
    cout << "[Deleted Node] : " << cl.deleteAtEnd() << endl;
    cout << "[Deleted Node] : " << cl.deleteAtBegin() << endl;
    cout << "[Circular Linked List] : ";
    cl.printCList();

    cl.insertAtBegin(1);
    cl.insertAtEnd(2);
    cl.insertAtEnd(3);
    cout << "[Circular Linked List] : ";
    cl.printCList();
    cout << "[Search Node Found] : " << cl.search(2) << endl;
    cout << "[Search Node Found] : " << cl.search(3) << endl;

    cl.insert(4, 4);
    cl.insert(5, 5);
    cout << "[Circular Linked List] : ";
    cl.printCList();
    cl.insert(6, 2);
    cout << "[Circular Linked List] : ";
    cl.printCList();
    return 0;
}
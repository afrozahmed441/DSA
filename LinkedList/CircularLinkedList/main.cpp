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
    return 0;
}
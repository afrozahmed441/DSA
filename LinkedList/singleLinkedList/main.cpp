#include <iostream>
#include "singleLinkedList.h"
using namespace std;

int main(){

    singleLinkedList l1;
    l1.insertAtBegin(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    cout << "[Before Delete] : ";
    l1.printList();
    cout << "[Deleted node data] : " << l1.deleteAtBegin() << endl;
    cout << "[Deleted node data] : " << l1.deleteAtEnd() << endl;
    cout << "[After Delete] : ";
    l1.printList();
    cout << "[Deleted node data] : " << l1.deleteAtBegin() << endl;
    cout << "[Deleted node data] : " << l1.deleteAtEnd() << endl;
    cout << "[Deleted node data] : " << l1.deleteAtEnd() << endl; 
    l1.printList();


 return 0;
}
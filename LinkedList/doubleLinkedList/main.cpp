#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

int main(){

    DoubleLinkedList dl;
    dl.insertAtBegin(1);
    dl.insertAtEnd(2);
    dl.insertAtEnd(3);
    dl.insertAtEnd(4);
    dl.insertAtEnd(5);
    dl.printDList();
    cout << "[Deleted Node] : " << dl.deleteAtBegin() << endl;
    cout << "[Deleted Node] : " << dl.deleteAtEnd() << endl;
    dl.printDList();
    cout << "[Deleted Node] : " << dl.deleteAtBegin() << endl;
    cout << "[Deleted Node] : " << dl.deleteAtEnd() << endl;
    cout << "[Deleted Node] : " << dl.deleteAtEnd() << endl;
    dl.printDList();

    dl.insertAtBegin(1);
    dl.insert(2, 2);
    dl.insert(3, 1);
    dl.printDList();
    cout << "[Search Node Found] : " << dl.search(2) << endl;
  return 0;
}
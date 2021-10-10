#ifndef _DOUBLELINKEDLIST_
#define _DOUBLELINKEDLIST_

struct node {
    int data;
    node *prev;
    node *next;
};

class DoubleLinkedList{
    node *head;

public:
    DoubleLinkedList();
    node *createNewNode(int);
    void insertAtBegin(int);
    void insertAtEnd(int);
    int deleteAtBegin();
    int deleteAtEnd();
    void printDList();
};

#endif
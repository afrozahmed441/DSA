#ifndef _CIRCULARLINKEDLIST_
#define _CIRCULARLINKEDLIST_

struct node{
    int data;
    node *next;
};

class CircularLinkedList{
    node *head;
    node *tail;
public:
    CircularLinkedList();
    node *createNewNode(int);
    void insertAtBegin(int);
    void insertAtEnd(int);
    int deleteAtBegin();
    int deleteAtEnd();
    void printCList();
};

#endif
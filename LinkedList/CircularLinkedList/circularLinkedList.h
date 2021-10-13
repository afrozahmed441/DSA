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
    void insert(int, int);
    int deleteAtBegin();
    int deleteAtEnd();
    int deleteNode(int);
    int search(int);
    void printCList();
};

#endif
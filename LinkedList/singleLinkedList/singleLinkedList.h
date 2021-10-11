#ifndef _SINGLELINKEDLIST_
#define _SINGLELINKEDLIST_

struct node {
    int data;
    node *next;
    node(int x) { 
        data = x;
        next = NULL; 
    }
};

class singleLinkedList{
    node *head;

public:
    singleLinkedList();
    node *createNewNode(int);
    void insertAtBegin(int);
    void insertAtEnd(int);
    void insert(int, int);
    int deleteAtBegin();
    int deleteAtEnd();
    int deleteNode(int);
    int search(int);
    void printList();
};

#endif
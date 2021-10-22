#ifndef _DEQUEUE_
#define _DEQUEUE_

/// structure of node
/// using double linked linked list to implement dequeue with head and tail pointers
struct Node {
    int data;
    Node *prev;
    Node *next;

};

class Dequeue {

    Node *front;
    Node *rear;
    int size;

public:
    Dequeue();
    Node *createNode(int);
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int getFront();
    int getRear();
    int getSize();
    bool isEmpty();

};

#endif
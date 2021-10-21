#ifndef _QUEUE_
#define _QUEUE_

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node *front;
    Node *rear;
    int siz;

public:
    Queue();
    void enqueue(int);
    int dequeue();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
    ~Queue();

};

#endif
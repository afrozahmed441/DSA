#ifndef _QUEUE_
#define _QUEUE_

class Queue {

    int front;
    int rear;
    int *que;
    int cap;

public:
    Queue(int);
    void enqueue(int);
    int dequeue();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
    bool isFull();
    ~Queue()

};

#endif
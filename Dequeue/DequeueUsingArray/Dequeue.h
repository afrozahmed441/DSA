#ifndef _DEQUEUE_
#define _DEQUEUE_

class Dequeue {

    int front;
    int rear;
    int *arr;
    int cap;
    int siz;

public:
    Dequeue(int);
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int getFront();
    int getRear();
    int getSize();
    bool isEmpty();
    bool isFull();

};


#endif
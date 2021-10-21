#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue(int n) {
    front = rear = -1;
    que = new int[n];
    cap = n;
}

void Queue::enqueue(int data) {
    /// if queue is full (rear == cap-1)
    if(rear == cap-1) return;
    /// if queue is empty 
    else if(front == -1 && rear == -1) {
        que[++rear] = data;
        ++front;
    }
    /// if queue has one or more elements
    else que[++rear] = data;
}

int Queue::dequeue() {
    int data;
    /// if queue is empty 
    if(front == -1 && rear == -1) data = -1;
    /// if there is only one element in the queue
    else if(front == rear && rear != -1) {
        data = que[front];
        front = rear = -1;
    }
    /// if there are more than one elements in queue
    else data = que[front++];
  return data;
}

int Queue::getFront() {
    if(front == -1) {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return que[front];
}

int Queue::getRear() {
    if(rear == -1) {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return que[rear];
}

int Queue::size() {
    if(rear == -1) return -1;
    return (rear+1);
}
bool Queue::isEmpty() {
    return (front == -1);
}

bool Queue::isFull() {
    return (rear+1 == cap);
}
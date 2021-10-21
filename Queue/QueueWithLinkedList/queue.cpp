#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
    front = NULL;
    rear = NULL;
    siz = 0;
}

void Queue::enqueue(int data) {
    Node *newNode = new Node(data);
    /// if the queue is empty
    if(front == NULL && rear == NULL) {
        front = newNode;
        rear = front;
        siz++;
    }
    /// if queue has atleast one node 
    else {
        rear->next = newNode;
        rear = rear->next;
        siz++;
    }
}

int Queue::dequeue() {
    int data;
    if(front == NULL && rear == NULL) data = -1;
    else if(front == rear && rear != NULL) {
        data = front->data;
        front = NULL;
        rear = NULL;
        siz--;
    }
    else {
        data = front->data;
        front = front->next;
        siz--;
    }
 return data;
}

int Queue::getFront() {
    if(front == NULL) return -1;
    return front->data;
}

int Queue::getRear() {
    if(rear == NULL) return -1;
    return rear->data;
}

int Queue::size() {
    return siz;
}

bool Queue::isEmpty() {
    return (front == NULL && rear == NULL);
}

Queue::~Queue() {
    delete(front);
    delete(rear);
}
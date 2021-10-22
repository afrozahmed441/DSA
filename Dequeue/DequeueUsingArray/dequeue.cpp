#include <iostream>
#include "Dequeue.h"
using namespace std;

Dequeue::Dequeue(int n) {
    front = rear = -1;
    arr = new int[n];
    cap = n;
    siz = 0;
}

void Dequeue::push_front(int data) {
    /// if dequeue is full
    if(rear == cap-1) return;
    /// if dequeue is empty 
    else if(front == -1 && rear == -1) {
        arr[++front] = data;
        ++rear;
    }
    /// if dequeue has more than one element
    else {
        /// move the elements from the last one step 
        for(int i = rear; i >= 0; i--) arr[i+1] = arr[i];
        /// insert the data at front
        arr[0] = data;
        /// update the rear
        rear++;
    }
    siz++;
}

void Dequeue::push_back(int data) {
    /// if dequeue is full
    if(rear == cap-1) return;
    /// if dequeue is empty
    else if(front == -1 && rear == -1) {
        arr[++rear] = data;
        ++front;
    }
    /// if dequeue has more than one element
    else arr[++rear] = data;
    siz++;
} 

int Dequeue::pop_front() {
    int data;
    /// if dequeue is empty
    if(front == -1) data = -1;
    /// if dequeue has only one element
    else if(front == rear && rear != -1) {
        data = arr[front];
        front = -1;
        rear = -1;
        siz--;
    }
    /// more than one element in dequeue
    else {
        data = arr[front++];
        siz--;
    }
 return data;
}

int Dequeue::pop_back() {
    int data;
    /// if dequeue is empty 
    if(front == -1 && rear == -1) data = -1;
    /// if dequeue has only one element
    else if(front == rear && front != -1) {
        data = arr[rear];
        rear = -1;
        front = -1;
        siz--;
    }
    /// if dequeue has more than one element
    else {
        data = arr[rear--];
        siz--;
    }
 return data;
}

int Dequeue::getFront() {
    if(front == -1) return -1;
    else return arr[front];
}

int Dequeue::getRear() {
    if(rear == -1) return -1;
    else return arr[rear];
}

int Dequeue::getSize() {
    if(rear == -1 && front == -1) return -1;
    else return (siz);
}

bool Dequeue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool Dequeue::isFull() {
    return (rear == cap-1);
}
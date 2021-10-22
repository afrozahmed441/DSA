#include <iostream>
#include "Dequeue.h"
using namespace std;

Dequeue::Dequeue() {
    front = NULL;
    rear = NULL;
    size = 0;
}

Node *Dequeue::createNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; 
  return newNode;
}

void Dequeue::push_front(int data) {
    Node *newNode = createNode(data);

    /// if dequeue is empty
    if(front == NULL && rear == NULL) {
        front = newNode;
        rear = front;
    }

    /// if dequeue has one or more elements
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

void Dequeue::push_back(int data) {
    Node *newNode = createNode(data);
    /// if dequeue is empty
    if(front == NULL && rear == NULL) {
        front = newNode;
        rear = front;
    }

    /// if dequeue has one or more than one element
    else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = rear->next;
    }
    size++;
}

int Dequeue::pop_front() {
    int data;
    /// if dequeue is empty
    if(front == NULL && rear == NULL) data = -1;
    /// if dequeue has only one element
    else if(front == rear && rear != NULL) {
        data = front->data;
        front = NULL;
        rear = NULL;
        size--;
    }
    /// more than one element 
    else {
        Node *n = front;
        data = front->data;
        front = front->next;
        front->prev = NULL;
        delete(n);
        size--;
    }
    return data;
}

int Dequeue::pop_back() {
    int data;
    /// if dequeue is empty 
    if(front == NULL && rear == NULL) data = -1;
    /// if dequeue has only one element
    else if(front == rear && rear != NULL) {
        data = rear->data;
        front = NULL;
        rear = NULL;
        size--;
    }
    /// more than one element 
    else {
        Node *n = rear;
        data = rear->data;
        rear = rear->prev;
        rear->next = NULL;
        delete(n);
        size--;
    }
    return data;
}

int Dequeue::getFront() {
    if(front == NULL) return -1;
    else return (front->data);
}

int Dequeue::getRear() {
    if (rear == NULL) return -1;
    else return (rear->data);
}

int Dequeue::getSize() {
    return size;
}

bool Dequeue::isEmpty() {
    return (front == NULL && rear == NULL);
}
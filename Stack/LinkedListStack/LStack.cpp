#include <iostream>
#include "LStack.h"

/// implementatio of the Stack using linked list

Stack::Stack() {
    head = NULL;
    s = 0;
}

void Stack::push(int data) {
    /// create new node
    node *n = new node();
    n->data = data;
    n->next = NULL;

    /// push
    n->next = head;
    head = n;
    s++;
}

int Stack::pop() {
    int data;
    if(head == NULL) return -1;
    else {
        data = head->data;
        node *n = head;
        head = head->next;
        s--;
        delete(n);
    }
    return data;
}

int Stack::peek() {
    if(head == NULL) return -1;
    return head->data;
}

int Stack::size() {
    return s;
}

bool Stack::isEmpty() {
    return (head == NULL);
}
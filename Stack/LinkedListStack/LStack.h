#ifndef _LSTACK_
#define _LSTACK_

struct node {
    int data;
    node *next;
};

class Stack {

    node *head;
    int s;

public:
    Stack();
    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();

};

#endif
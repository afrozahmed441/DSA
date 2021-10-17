#ifndef _ASTACK_
#define _ASTACK_

/// Implementing Stack Data Structure using array
/// class strucutre
class Stack {

    int *arr;
    int cap;
    int top;

public:
    Stack(int);
    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
};

#endif
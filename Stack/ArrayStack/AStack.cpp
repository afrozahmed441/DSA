#include <iostream>
#include "AStack.h"
using namespace std;

/// implementation of Stack using array 

Stack::Stack(int c) {
    arr = new int[c];
    cap = c;
    top = -1;
}

void Stack::push(int data) {
    if(top == cap-1) cout << "Stack overflow" << endl;
    else {
        arr[++top] = data;
        cout << "data " << data << " successfully pushed into stack" << endl;
    }
}

int Stack::pop() {
    if(top == -1) cout << "Stack underflow" << endl;
    return arr[top--];
}

int Stack::peek() {
    if(top == -1) cout << "Stack is empty" << endl;
    return arr[top];
}

int Stack::size() {
    return (top+1);
}

bool Stack::isEmpty() {
    return (top == -1);
}
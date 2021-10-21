#include <iostream>
#include <stack> 
using namespace std;

/*

- Problem   : Given a series of push and pop and getMin(), we need to print the min element in the stack at any instance

- input   : A series of push, pop, getMin 
- output  : min element when getMin is called 

- Example Test Case:
  i/o   :  push(2), push(3), push(5), getMin(), pop(), getMin(), push(1), getMin()
  o/p   :  2  3  1  (return from getMin)


*/

//// ------------------------------- Main Logic --------------------------------
/// Using O(N) Auxiliary space to keep track of min element
/// Global Stacks
stack<int> st;
stack<int> ms;

void push(int data) {
    if(ms.empty()) {
        ms.push(data);
        st.push(data);
    }
    else if(ms.top() >= data) {
        ms.push(data);
        st.push(data);
    } 
    else {
        st.push(data);
    }
}

int pop() {
    int data;
    if(ms.empty()) cout << "-1" << endl;
    else if(ms.top() == st.top()){
        ms.pop();
        data = st.top();
        st.pop();
    }
    else {
        data = st.top();
        st.pop();
    }
    return data;
}

int getMin() {
    return ms.top();
}

int main() {

    cout << "Test Case 1 : " << endl;
    push(1);
    push(3);
    cout <<"Min : " << getMin() << endl;
    pop();
    pop();
    push(2);
    cout <<"Min : " << getMin() << endl;
    push(1);
    cout <<"Min : " << getMin() << endl;
    cout << endl;

 return 0;
}
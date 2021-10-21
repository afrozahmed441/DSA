#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   : Given a series of push and pop and getMin(), we need to print the min element in the stack at any instance without using extra space in O(1) Space

- input   : A series of push, pop, getMin 
- output  : min element when getMin is called 

- Example Test Case:
  i/o   :  push(2), push(3), push(5), getMin(), pop(), getMin(), push(1), getMin()
  o/p   :  2  3  1  (return from getMin)


*/

//// --------------------------- Main Logic -------------------------------------
void push(stack<int> &st, int &min, int data) {
    if(st.empty()) {
        st.push(data);
        min = data;
    }
    else if(data <= min) {
        /// if data is only positive number then st.push(data - min)
        st.push(2*data - min);
        min = data;
    }
    else st.push(data);
}

int pop(stack<int> &st, int &min) {
     int top = st.top();
     int data;
     if(top <= min) {
         data = min;
         /// if data is only positive numbers then min = min - top and if condition is top <= 0
         min = 2*min - top;
     }
     else data = top;
     st.pop();
     return data;
}

int peek(stack<int> &st, int &min) {
    int top = st.top();
    /// if data is only positive numbers then the condition would be top <= 0
    return ((top <= min) ? min : top);
}

/// main function
int main() {

    stack<int> st;
    int min;
    cout << "Test Case 1 : " << endl;
    push(st, min, 3);
    push(st, min, 2);
    push(st, min, 1);
    cout << "Min : " << min << endl;
    pop(st, min);
    cout << "Min : " << min << endl;
    push(st, min, -1);
    cout << "Min : " << min << endl;
    cout << endl;


 return 0;
}
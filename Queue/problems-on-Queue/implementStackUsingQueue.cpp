#include <iostream>
#include <queue>
using namespace std;

/*
- Problem   : Implement a Stack Data Strcuture using Queue Data Structure

- input     :  A series of Stack operations
- ouput     :  Stack output

*/

///// ---------------------------- Main Logic ----------------------------------
/// return stack top element
int top(queue<int> &q) {
    if(q.empty()) return -1;
    else return q.front();
}

/// push function
void push(queue<int> &q, int data) {

    if(q.empty()) q.push(data);
    else {
        queue<int> q2;
        q2.push(data);
        while(!q.empty()) {
            q2.push(q.front());
            q.pop();
        }

        queue<int> q3 = q;
        q = q2;
        q2 =q;
    }
}

/// pop function 
int pop(queue<int> &q) {
    int data;
    if(q.empty()) data = -1;
    else {
        data = q.front();
        q.pop();
    }
    return data;
}

/// main function 
int main() {

    queue<int> que;
    for(int i = 1; i <= 5; i++) push(que, i);

    cout << "TOP : " << top(que) << endl;
    cout << "POP : " << pop(que) << endl;
    cout << "TOP : " << top(que) << endl;
    push(que, 0);
    cout << "TOP : " << top(que) << endl;
    cout << endl;
    
 return 0;
}
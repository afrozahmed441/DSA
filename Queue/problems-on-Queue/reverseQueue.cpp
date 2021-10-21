#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*

- Problem   :  Given a queue, reverse the queue

- input     : queue
- output    : reverse queue

- Example Test Case:
  i/o : 1 2 3 4 5
  o/p : 5 4 3 2 1

  i/o : 1 3 5 7
  o/p : 7 5 3 1

  i/o : 2 4 6 8
  o/p : 8 6 4 2

*/

/// insert queue with random data
void loadQueue(queue<int> &q, int n) {
    for(int i = 1; i <= n; i++) q.push(i);
}

/// --------------------------- Main Logic ----------------------------------
void reverseQueue(queue<int> &q) {
    stack<int> st;
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

}

void reverseRecQueue(queue<int> &q) {
    if(q.empty()) return;
    int x = q.front();
    q.pop();
    reverseRecQueue(q);
    q.push(x);
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {

    cout << "------------------ iteration ------------------------------ " << endl;
    queue<int> q;
    loadQueue(q, 5);
    cout << "[Before reverse] : ";
    printQueue(q);
    cout << "[After reverse] : ";
    reverseQueue(q);
    printQueue(q);
    cout << endl;

    cout << "------------------ recersion ------------------------------ " << endl;
    queue<int> q2;
    loadQueue(q2, 5);
    cout << "[Before reverse] : ";
    printQueue(q2);
    cout << "[After reverse] : ";
    reverseRecQueue(q2);
    printQueue(q2);
    cout << endl;

    return 0;
}
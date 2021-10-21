#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front : " << q.getFront() << endl;
    cout << "Rear : " << q.getRear() << endl;
    cout << "Size : " << q.size() << endl;
    cout << "Dequeue : " << q.dequeue()  << endl;
    cout << "Front : " << q.getFront() << endl;
    cout << "Rear : " << q.getRear() << endl;
    cout << "Size : " << q.size() << endl;
    cout << endl; 

}
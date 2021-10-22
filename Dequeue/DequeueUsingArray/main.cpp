#include <iostream>
#include "Dequeue.h"
using namespace std;

int main() {

    Dequeue deq(10);
    
    for(int i = 1; i <= 5; i++) deq.push_front(i);

    cout << "Front : " << deq.getFront() << endl;
    cout << "Rear : " << deq.getRear() << endl;
    cout << "Size : " << deq.getSize() << endl;
    cout << "Empty : " << deq.isEmpty() << endl;

    cout << "POP_BACK : " << deq.pop_back() << endl;
    cout << "Size : " << deq.getSize() << endl;
    cout << "Rear : " << deq.getRear() << endl;

    cout << "POP_FRONT : " << deq.pop_front() << endl;
    cout << "Size : " << deq.getSize() << endl;
    cout << "FRONT : " << deq.getFront() << endl;

    cout << endl;

  return 0;
}
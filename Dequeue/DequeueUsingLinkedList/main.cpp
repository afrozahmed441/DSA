#include <iostream>
#include "Dequeue.h"
using namespace std;

int main() {

    Dequeue dq;
    
    for(int i = 1; i <= 5; i++) dq.push_front(i);

    cout << "FRONT : " << dq.getFront() << endl;
    cout << "REAR :  " << dq.getRear() << endl;
    cout << "SIZE : " << dq.getSize() << endl;
    dq.push_back(0);
    cout << "REAR : " << dq.getRear() << endl;
    dq.push_front(6);
    cout << "FRONT : " << dq.getFront() << endl;
    cout << "Size : " << dq.getSize() << endl;  
    cout << "POP BACK: " << dq.pop_back() << endl;
    cout << "REAR : " << dq.getRear() << endl;
    cout << "POP FRONT : " << dq.pop_front() << endl;
    cout << "FRONT : " << dq.getFront() << endl;
    cout << "Size : " << dq.getSize() << endl;  

    cout << endl;

}
#include <iostream>
#include "MinHeap.h"
using namespace std;

int main() {

    MinHeap m(10);
    m.insert(10);
    m.insert(5);
    m.insert(6);
    m.insert(1);
    m.insert(2);

    cout << "Min Heap : ";
    m.printMinHeap();    

    cout << "Extract Min : " << m.extractMin() << endl;
    cout << "Min Heap : ";
    m.printMinHeap();

    cout << "Delete : " <<  m.deleteKey(2) << endl;
    cout << "Min Heap : ";
    m.printMinHeap();

 return 0;
}
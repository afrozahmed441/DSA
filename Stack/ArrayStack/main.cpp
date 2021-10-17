#include <iostream>
#include "AStack.h"
using namespace std;

int main() {

    Stack s(5);
    for(int i = 5; i>=1; i--) s.push(i);
    cout << "[Deleted] : " << s.pop() << endl;
    cout << "[Top] : " << s.peek() << endl;
    cout << "[Deleted] : " << s.pop() << endl;
    cout << "[Top] : " << s.peek() << endl;
    cout << "[Empty] : " << s.isEmpty() << endl;    
    cout << endl;
    return 0;
}
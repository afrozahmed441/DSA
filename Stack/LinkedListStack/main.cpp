#include <iostream>
#include "LStack.h"
using namespace std;

int main() {

    Stack s;

    for(int i = 1; i <= 5; i++) s.push(i);

    cout << "[Stack Top] : " << s.peek() << endl;
    cout << "[Deleted] : " << s.pop() << endl;
    cout << "[size] : " << s.size() << endl;
    cout << "[Stack Top] : " << s.peek() << endl;
    cout << "[Deleted] : " << s.pop() << endl;
    cout << "[Stack Top] : " << s.peek() << endl;
    cout << "[size] : " << s.size() << endl;
    cout << endl;

 return 0;
}
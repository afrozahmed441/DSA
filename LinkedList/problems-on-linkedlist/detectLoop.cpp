#include <iostream>
#include <unordered_set>
using namespace std;

/*

- Problem   :   Given a Single Linked List, check whether there is a loop in the linked list 

- input     :  head of the single linked list
- output    :  true or false

- Example Test Cases
  i/o : 1->2->3->4->5->addressofNode->1
  o/p : true

  i/o : 1->2->addreesofNode->1
  o/p : true

  i/o : 1->3->4
  o/p : false

*/

/// node structure
struct node {
    int data;
    node *next;

    node(int x){
        data = x;
        next = NULL;
    }

};

/// create a random single linked list
node *createList(int n) {
    node *head = new node(1);
    node *temp = head;

    for(int i = 2; i <= n; i++){
        node *n = new node(i);
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    /// making a loop
    temp->next->next = head;
    return head;
}

/// display linked list 
void print(node *head) {
    if(head == NULL) cout << "Empty" << endl;
    else {
        node *temp = head;
        unordered_set<node *> s;
        while(temp != NULL && s.find(temp) == s.end()) {
            cout << temp->data << "->";
            s.insert(temp);
            temp = temp->next;
        }
        cout << temp->data << "->NULL" << endl;
    }
}

/// ------------------------------------ Main Logic ----------------------------

/// using hashing method to detect a loop in the single linked list
/// Time Complexcity : O(N), where N is number of nodes or lenght of the linked list
/// Auxiliary Space  : O(N), where N is number of nodes
bool detectLoop(node *head) {
    unordered_set<node *> s;
    node *temp = head;
    while(temp != NULL) {
        if(s.find(temp) != s.end()) return true;
        else {
            s.insert(temp);
            temp = temp->next;
        }
    }
    return false;
}

/// using slow and fast pointers, also called as floyd's cycle detection algo (efficient solution)
/// Time Complexcity : O(N), where N is number of nodes 
/// Auxiliary Space  : O(1)
bool detectLoopF(node *head) {
    node *s = head, *f = head;
    while(f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
        if(s == f) return true;
    }
    return false;
}

int main() {

    cout << "-------------------- Using Hashing Method ----------------------------" << endl;
    cout << "Test Case 1 : " << endl;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    cout << "[Loop] : " << detectLoop(head) << endl;

    cout << "-------------------- Using Floyd's Method ----------------------------" << endl;
    cout << "Test Case 1 : " << endl;
    node *head2 = createList(5);
    cout << "[Linked List] : ";
    print(head2);
    cout << "[Loop] : " << detectLoop(head2) << endl;

    
 return 0;
}
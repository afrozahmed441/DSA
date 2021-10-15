#include <iostream>
using namespace std;

/*

- Problem   : Given a Single linked list, we need to segregate even and odd nodes as show in the test case

- input     : head of the linked list
- output    : linked list as show in the test case

- Example Test Cases:
  i/o : 1->2->3->4->5
  o/p : 2->4->1->3->5

  i/o : 1->3->2->4
  o/p : 2->4->1->3

  i/o : 2->4->6
  o/p : 2->4->6

  i/o : 1->3->5
  o/p : 1->3->5

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
    
    for(int i = 2; i <= n; i++){
        node *temp = head;
        node *n = new node(i);
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    return head;
}

/// display linked list 
void print(node *head) {
    if(head == NULL) cout << "Empty" << endl;
    else {
        node *temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

/// ------------------------------ Main Logic -----------------------------------
node *evenOddList(node *head) {
    node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
    
    for(node *temp = head; temp != NULL; temp = temp->next) {
        if(temp->data % 2 == 0) {
            if(es == NULL) { es = temp; ee = es; }
            else { ee->next = temp; ee = ee->next; }
        }
        else {
            if(os == NULL) { os = temp; oe = os; }
            else { oe->next = temp; oe = oe->next; }
        }
    }
    
    if(os == NULL || es == NULL) return head;

    ee->next = os;
    oe->next = NULL;
    return es;
}

/// main function
int main() {

    cout << "Test Case 1 : " << endl;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    head = evenOddList(head);
    cout << "[Linked List] : ";
    print(head);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    node *head2 = createList(6);
    cout << "[Linked List] : ";
    print(head2);
    head2 = evenOddList(head2);
    cout << "[Linked List] : ";
    print(head2);
    cout << endl;

    cout << "Test Case 3 : " << endl;
    node *head3 = createList(10);
    cout << "[Linked List] : ";
    print(head3);
    head3 = evenOddList(head3);
    cout << "[Linked List] : ";
    print(head3);
    cout << endl;

    return 0;
}
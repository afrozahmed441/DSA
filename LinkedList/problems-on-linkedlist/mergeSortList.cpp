#include <iostream>
using namespace std;

/*

- Problem   : Given Two Sorted Single Linked Lists, merge the two sorted linked lists

- input     : head pointer of two sorted linked lists
- output    : one sorted linked list

- Example Test Cases
  i/o : 1->3->5, 2->4->6
  o/p : 1->2->3->4->5->6

  i/o : 4->8->12, 1->2->3
  o/p : 1->2->3->4->8->12

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

/// ------------------------------- Main Logic -----------------------------------
node *mergeSortedLists(node *h1, node *h2) {
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    node *head = NULL, *tail = NULL;
    if(h1->data <= h2->data) {
        head = tail = h1;
        h1 = h1->next;
    } else {
        head = tail = h2;
        h2 = h2->next;
    }

    while(h1 != NULL && h2 != NULL) {
        if(h1->data <= h2->data) {
            tail->next = h1;
            tail = tail->next;
            h1 = h1->next;
        } else {
            tail->next = h2;
            tail = tail->next;
            h2 = h2->next;
        }
    }

    if(h1 == NULL) tail->next = h2;
    else tail->next = h1;
    return head;
}

int main() {

    node *head1 = createList(3);
    node *head2 = createList(5);
    cout << "[Linked List 1] : ";
    print(head1);
    cout << "[Linked List 2] : ";
    print(head2);
    node *mergeHead = mergeSortedLists(head1, head2);
    cout << "[Merged Linked List] : ";
    print(mergeHead);
    cout << endl;
    
    return 0;
}
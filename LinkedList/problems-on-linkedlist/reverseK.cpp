#include <iostream>
using namespace std;

/*

- Problem   :  Given Linked List reverse the Linked List in group k

- input     :  head of the linked list
- output    :  Linked List reversed in the group of k 

- Example Test Cases : 
  i/o : 1->2->3->4->5->6, k = 3
  o/p : 3->2->1->6->5->4 

  i/o : 1->2->3->4->5, k = 2
  o/p : 2->1->4->3->4

  i/o : 1->2->3->4->5, k = 3
  o/p : 3->2->1->5->4

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

/// ------------------------- Main Logic ------------------------------------------
node *reverseKList(node *head, int k) {
    node *cur = head, *prevFirst = NULL, *newHead = NULL;
    bool fp = true;
    while(cur != NULL) {
        node *first = cur, *prev = NULL;
        int c = 0;
        while(cur != NULL && c < k) {
            node *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            c++;
        }
        if(fp) {
            newHead = prev;
            fp = false;
        }
        else prevFirst->next = prev;
        prevFirst = first;
    }
    return newHead;
}


/// main function
int main() {

    cout << "Test Case 1 : " << endl;
    node *head = createList(6);
    int k = 3;
    cout << "[Linked List] : ";
    print(head);
    head = reverseKList(head, k);
    cout << "[Linked List] : ";
    print(head);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    node *head2 = createList(5);
    int k2 = 2;
    cout << "[Linked List] : ";
    print(head2);
    head2 = reverseKList(head2, k2);
    cout << "[Linked List] : ";
    print(head2);
    cout << endl;

    cout << "Test Case 3 : " << endl;
    node *head3 = createList(5);
    int k3 = 3;
    cout << "[Linked List] : ";
    print(head3);
    head3 = reverseKList(head3, k3);
    cout << "[Linked List] : ";
    print(head3);
    cout << endl;

 return 0;
}
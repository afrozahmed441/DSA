#include <iostream>
using namespace std;

/*

- Problem   :  Given a linked list swap the nodes in the linked list in pair

- input     : head of the linked list
- ouput     : pair wise swaped linked list

- Example Test Cases: 
  i/o : 1->2->3->4
  o/p : 2->1->4->3

  i/o : 1->2->3->4->5
  o/p : 2->1->4->3->5

  i/o : 1->2
  o/p : 2->1

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

/// ------------------------------- Main Logic ------------------------------------

/// swap the data in the linked list nodes
void pairSwapNodes(node *head) {
        node *temp = head;
        while(temp != NULL && temp->next != NULL) {
            int data = temp->data;
            temp->data = temp->next->data;
            temp->next->data = data;
            temp = temp->next->next;
        }
}

/// swap the pointers in the linked list
node *pairSwapNodesLink(node *head) {
    if(head == NULL || head->next == NULL) return head;
    else {
        node *cur = head->next->next;
        node *prev = head;
        head = head->next;
        head->next = prev;

        while(cur != NULL && cur->next != NULL) {
            prev->next = cur->next;
            prev = cur;
            node *next = cur->next->next;
            cur->next->next = cur;
            cur = next;
        }
        prev->next = cur;
    }
    return head;
}

int main() {
    cout << "------------------ Swaping Data ------------------------------" << endl;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    pairSwapNodes(head);
    cout << "[Linked List] : ";
    print(head);
    cout << endl;

    cout << "------------------ Swaping Links ------------------------------" << endl;
    node *head2 = createList(5);
    cout << "[Linked List] : ";
    print(head2);
    head2 = pairSwapNodesLink(head2);
    cout << "[Linked List] : ";
    print(head2);
    cout << endl;


  return 0;
}
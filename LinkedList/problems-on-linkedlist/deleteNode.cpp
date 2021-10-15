#include <iostream>
using namespace std;

/*

- Problem   : Given a addrees to the node in the linked list, delete the node

- input     : address of the node 
- output    : linked list without the node which is given to delete

- Example Test Case : 
  i/o : 1->2->3->4->5, addressOfNode = 2
  o/p : 1->3->4->5

  i/o : 1->2->3, addreeOfNode = 2
  o/p : 1->3

  i/o : 1->2->4->5, addressOfNode = 4
  o/p : 1->2->5

  NOTE : given node address will not be the last node in the linked list
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

/// return addressOf given node
node *addressOfNode(node *head, int data) {
    node *temp = head;
    while(temp != NULL) {
        if(temp->data == data) return temp;
        else temp = temp->next;
    }
    return NULL;
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

/// ----------------------------------- Main Logic -------------------------------
void deleteNode(node *temp) {
    node *n = temp->next;
    temp->data = temp->next->data;
    temp->next = temp->next->next;
    delete(n);
}

int main() {

    cout << "Test Case 1: " << endl;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    int data = 2;
    node *n = addressOfNode(head, data);
    deleteNode(n);
    cout << "[Node to delete] : " << data << endl;
    cout << "[Linked List] : ";
    print(head);
    cout << endl;

    cout << "Test Case 2: " << endl;
    node *head2 = createList(5);
    cout << "[Linked List] : ";
    print(head2);
    int data2 = 1;
    node *n2 = addressOfNode(head2, data2);
    deleteNode(n2);
    cout << "[Node to delete] : " << data2 << endl;
    cout << "[Linked List] : ";
    print(head2);

 return 0;
}
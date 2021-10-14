#include <iostream>
using namespace std;

/*

- Problem : Given a Sorted Single Linked List and data, insert the node with given data into the linked list in a correct position in the linked list so that the linked list remains sorted

- input  : head of the linked list and data to be inserted
- output : linked list with given data node in the linked list and sorted (as shown below)

- Example Test Cases:
  i/o : 1->2->3, data = 4
  o/p : 1->2->3->4

  i/o : 1->5->6->7, data = 4
  o/p : 1->4->5->6->7

  i/o : 4->5->8->9, data = 1
  o/p : 1->4->5->8->9

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
        node *n = new node(i+1);
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
node *sortedInsert(node *head, int data) {
    node *newNode = new node(data);
    /// no nodes in the linked list
    if(head == NULL) head = newNode;

    /// compare with head
    else if(head->data > data) {
        newNode->next = head;
        head = newNode;
    }

    /// compare with other nodes
    else {
        node *temp = head;
        while(temp->next != NULL && temp->next->data < data) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main() {

    node *head = createList(3);
    int data = 2;
    cout << "Test Case 1 : " << endl;
    cout << "[Linked List] : ";
    print(head);
    head = sortedInsert(head, data);
    cout << "[Linked List] : ";
    print(head);

    node *head2 = createList(3);
    int data2 = 0;
    cout << "Test Case 2 : " << endl;
    cout << "[Linked List] : ";
    print(head2);
    head2 = sortedInsert(head2, data2);
    cout << "[Linked List] : ";
    print(head2);

    node *head3 = createList(3);
    int data3 = 5;
    cout << "Test Case 3 : " << endl;
    cout << "[Linked List] : ";
    print(head3);
    head3 = sortedInsert(head3, data3);
    cout << "[Linked List] : ";
    print(head3);

    return 0;
}
#include <iostream>
using namespace std;

/*

- Problem : Given a Head of linked list reverse the linked list 

- input  :  head of linked list
- ouput  :  reversed linked list

- Example Test Case :
  i/o : 1->2->3->4->5
  o/p : 5->4->3->2->1

  i/o : 1->2->3
  o/p : 3->2->1

  i/o : 1
  o/p : 1

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

//// -------------------------- Main Logic ----------------------------------------
node *reverseList(node *head){
    
    if(head == NULL || head->next == NULL) return head;
    else {
        node *prev, *cur, *next;
        prev = NULL;
        cur = head;
        while(cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
}

int main() {

    cout << "Test Case 1 : " << endl;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    cout << "[Linked List] : ";
    head = reverseList(head);
    print(head);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    node *head2 = createList(3);
    cout << "[Linked List] : ";
    print(head2);
    cout << "[Linked List] : ";
    head2 = reverseList(head2);
    print(head2);
    cout << endl;

    cout << "Test Case 3 : " << endl;
    node *head3 = createList(1);
    cout << "[Linked List] : ";
    print(head3);
    cout << "[Linked List] : ";
    head3 = reverseList(head3);
    print(head3);
    cout << endl;

    cout << "Test Case 4 : " << endl;
    node *head4 = createList(2);
    cout << "[Linked List] : ";
    print(head4);
    cout << "[Linked List] : ";
    head4 = reverseList(head4);
    print(head4);
    cout << endl;

    return 0;
}
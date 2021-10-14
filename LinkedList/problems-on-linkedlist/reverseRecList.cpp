#include <iostream>
using namespace std;

/*

- Problem   : Given Single Linked List reverse the Linked List using recersion 

- input     : head of the single linked list
- output    : reverse linked list

- Example Test Cases:
  i/o : 1->2->3->4->5
  O/p : 5->4->3->2->1

  i/o : 1->2->3
  o/p : 3->2->1

  i/o : 1->2
  o/p : 2->1

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


/// ----------------------------------- Main Logic --------------------------------
node *reverseRecList(node *head) {
    /**
     * Base Case : head is NULL or head->next is NULL return head
     * else we store the newHead is a variable restHead, when the list reaches end then it returns the address of last node
     * after last node address is returned we make the current head next as the rest_tail 
     * and then rest_tail points to the current head, then we make current head next as null and return the last node address (new Head)
    */
    if(head == NULL || head->next == NULL) return head;
    node *restHead = reverseRecList(head->next);
    node *restTail = head->next;
    restTail->next = head;
    head->next = NULL;
    return restHead;
}

//// NOTE : TRY RECERSION TREE ON THE PAPER :)

int main() {

    cout << "Test Case 1 : " << endl;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    head = reverseRecList(head);
    cout << "[Linked List] : ";
    print(head);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    node *head2 = createList(1);
    cout << "[Linked List] : ";
    print(head2);
    head2 = reverseRecList(head2);
    cout << "[Linked List] : ";
    print(head2);
    cout << endl;

 return 0;
}
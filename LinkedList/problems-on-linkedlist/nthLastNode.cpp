#include <iostream>
using namespace std;

/*

- Problem   : Given Linked List, Find nth Last node in the linked list

- input     : head of the linked list and n (n is integer and always less than lenght of the linked list)
- output    : nth Last node data in the linked list  

- Example Test Case : 
  i/o : 1->2->3->4->5, n = 2
  o/p : 4

  i/o : 1->2->3, n = 1
  o/p : 3

  i/o : 1->2->3->4->5, n = 4
  o/p : 2

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

/// ------------------------------------ Main Logic ------------------------------
void nthLastNode(node *head, int n) {
    /**
     * if head is null print -1 
     * else take two pointers slow and fast and slow and fast pointer point to head initialy
     * first move the fast pointer n places ahead from slow (move fast pointer n times before moving slow)
     * then move the slow pointer one node at a time until the fast pointer reachers NULL (end of the list)
     * then print the data of the node which slow pointer is pointing to.
    */
    if(head == NULL) cout << -1 << endl;
    else {
        node *s, *f;
        s = f = head;
        /// move fast pointer n nodes a ahead
        for(int i = 1; i <= n; i++) f = f->next;
        /// then move slow pointer one node at a time until fast reaches NULL
        while(f != NULL) {
            s = s->next;
            f = f->next;
        }
        cout << s->data << endl;
    }
}

/// main function
int main() {

    cout << "Test Case 1 : " << endl; 
    node *head = createList(5);
    int n = 2;
    cout << "[Linked List] : ";
    print(head);
    cout << "[ " << n << " last node is] : ";
    nthLastNode(head, n);

    cout << "Test Case 2 : " << endl; 
    node *head2 = createList(6);
    int n2 = 4;
    cout << "[Linked List] : ";
    print(head2);
    cout << "[ " << n2 << " last node is] : ";
    nthLastNode(head2, n2);

    cout << "Test Case 3 : " << endl; 
    node *head3 = createList(1);
    int n3 = 1;
    cout << "[Linked List] : ";
    print(head3);
    cout << "[ " << n3 << " last node is] : ";
    nthLastNode(head3, n3);

    cout << "Test Case 4 : " << endl; 
    node *head4 = createList(5);
    int n4 = 5;
    cout << "[Linked List] : ";
    print(head4);
    cout << "[ " << n4 << " last node is] : ";
    nthLastNode(head4, n4);

 return 0;
}
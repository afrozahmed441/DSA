#include <iostream>
using namespace std;

/*

- Problem   :  Given a Sorted Linked List remove duplicate nodes from the linked list

- input     :  head of the linked list
- output    :  linked list without any duplicate nodes

- Example Test Cases 
  i/o : 1->2->3->3->4->5
  o/p : 1->2->3->4->5

  i/o : 1->2->2->3->3->4
  o/p : 1->2->3->4

  i/o : 1->1
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
node *createList(int n, int data) {
    node *head = new node(1);
    
    for(int i = 2; i <= n; i++){
        node *temp = head;
        node *n = new node(data);
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

//// ---------------------------------- Main Logic --------------------------------
void removeDuplicateNodes(node *head) {
    /**
     * 1. Check if head is NULL or not, if head is NULL return
     * 2. if head is NOT NULL, then iterate through the linked list one node at a time.
     * 3. while iterating through the linked list check if the current node data is equal to next node data
     * 4. if it is equal then store the address of the next node in a temp node and make current node next point to next node of next and delete the next node
     * 5. else just move the current node to next node.
    */
    if(head == NULL) return;
    else {
        node *temp = head;
        while(temp != NULL && temp->next != NULL) {
            if(temp->next->data == temp->data) {
                node *n = temp->next;
                temp->next = temp->next->next;
                delete(n);
            }
            else temp = temp->next;
        }
    }
}

int main() {

    cout << "Test Case 1 : " << endl;
    node *head = createList(5, 3);
    cout << "[Linked List] : ";
    print(head);
    removeDuplicateNodes(head);
    cout << "[Linked List] : ";
    print(head);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    node *head2 = createList(5, 1);
    cout << "[Linked List] : ";
    print(head2);
    removeDuplicateNodes(head2);
    cout << "[Linked List] : ";
    print(head2);
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

/*

- Problem :  Find the middle node of the linked list 

- input : head of the linked list
- ouput : middle node data

- Example Test Cases : 
  i/o : 1->2->3->4->5
  o/p : 3

  i/o : 1->2->3->4->5->6
  o/p : 4

  i/o : 1->2
  o/p : 2

  i/o : 2
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

/// -------------------------------- Main Logic ---------------------------------
void middleNode(node *head) {
    /**
     * first check if the head is null or not if head is NULL then print -1
     * if head is not null then we take two pointers fast and slow
     * slow pointer points to head and fast pointer points to head
     * slow pointer moves one node at a time
     * fast pointer moves two nodes at a time
     * when fast next is NULL or when fast pointer reaches NULL (end of the list) then slow points to middle node in the linked list
     * Note: In Case of even Lenght Linked List fast pointer reaches NULL when slow pointer reaches middle Node.
     * Note: In Case of odd Lenght Linked List fast pointer reaches last node when slow pointer reaches middle Node.
    */
    if(head == NULL) cout << -1 << endl;
    else {
        node *slow = head , *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
    }
}

int main() {

    cout << "Test Case 1 : ";
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    cout << "[Middle Node] : ";
    middleNode(head);
    cout << endl;

    cout << "Test Case 2 : ";
    node *head2 = createList(2);
    cout << "[Linked List] : ";
    print(head2);
    cout << "[Middle Node] : ";
    middleNode(head2);
    cout << endl;

    cout << "Test Case 3 : ";
    node *head3 = createList(4);
    cout << "[Linked List] : ";
    print(head3);
    cout << "[Middle Node] : ";
    middleNode(head3);
    cout << endl;   

    return 0;
}
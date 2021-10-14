#include <iostream>
using namespace std;

/*

- Problem : Given a Linked List head and data, find the node in the linked list and return the position of the node in the linked list
            if the node with given data is not present in the linked list return -1

- input   : head of linked list and data
- output : position of node in the linked list

- Example Test Cases 
  i/o : 1->2->3->4->5, data = 5
  o/p : 5

  i/o : 1->3->5->7, data = 3
  o/p : 2

  i/o : 1->2->3, data = 1
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

/// ----------------------- Main Logic Here ----------------------------------------

/// using iteration 
int search(node *head, int data){
    /**
     * if head is NULL return -1
     * Else Travel through the linked list 
     * create a variable pos to keep track of the pos of node in the linked list
     * will iterating through the linked list check if the node data is equal to given data
     * if node data and given data are equal return the pos variable
     * if there is no match for given data then return -1
    */
    if(head == NULL) return -1;
    else {
        int pos = 1;
        node *temp = head;
        while(temp != NULL){

            if(temp->data == data) return pos;
            else {
                pos++;
                temp = temp->next;
            }
        }
    }
    return -1;
}

/// using recersion
int searchRec(node *head, int data){
    /**
     * Base Case : if head is NULL return -1
     * else check if the head data is equal to the given data 
     * if it is equal then return 1
     * else move to the next node until we find the node with given data or head is NULL
    */
    if(head == NULL) return -1;
    if(head->data == data) return 1;
    else {
        int res = searchRec(head->next, data);
        if(res == -1) return -1;
        else return (res+1);
    }
}

int main() {

    cout << "----------------- Using iteration method ------------------" << endl;
    cout << "Test Case 1 : " << endl;
    int data = 2;
    node *head = createList(5);
    cout << "[Linked List] : ";
    print(head);
    cout << "[Node to Search] : " << data << endl;
    cout << "[Node Position in the Linked List] : " << search(head, data) << endl;

    cout << "Test Case 2 : " << endl;
    int data2 = 7;
    node *head2 = createList(5);
    cout << "[Linked List] : ";
    print(head2);
    cout << "[Node to Search] : " << data2 << endl;
    cout << "[Node Position in the Linked List] : " << search(head2, data2) << endl;

    cout << "----------------- Using recersion method ------------------" << endl;
    cout << "Test Case 1 : " << endl;
    int data3 = 3;
    node *head3 = createList(5);
    cout << "[Linked List] : ";
    print(head3);
    cout << "[Node to Search] : " << data3 << endl;
    cout << "[Node Position in the Linked List] : " << searchRec(head3, data3) << endl;

    cout << "Test Case 2 : " << endl;
    int data4 = 7;
    node *head4 = createList(5);
    cout << "[Linked List] : ";
    print(head4);
    cout << "[Node to Search] : " << data4 << endl;
    cout << "[Node Position in the Linked List] : " << searchRec(head4, data4) << endl;



    return 0;
}
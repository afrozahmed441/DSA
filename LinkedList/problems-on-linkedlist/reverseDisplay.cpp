#include <iostream>
#include <stack>
using namespace std;

/*

- Problem : Given a Single Linked List display the data in the linked list in reverse order

- input  : single linked list head
- output : linked list data display in reverse as given in example test cases

- Example Test Cases
  i/o : 1->2->3->4->5
  o/p : 5->4->3->2->1

  i/o : 1->3->5->7
  o/p : 7->5->3->1

  i/o : 1->2
  o/p : 2->1

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

/// --------------- Main Logic here ---------------------
/// using stack data structure
void displayRevStack(node *head){
    /**
     * Create a empty stack
     * Traverse through the Single linked list
     * while traveling through store the data in the linked list in stack
     * print the stack till it is empty 
    */
    stack<int> s;
    node *temp = head;
    while(temp != NULL) {
        s.push(temp->data);
        temp = temp->next;
    }

    while(!s.empty()) {
        cout << s.top() << "->";
        s.pop();
    }

    cout << "NULL" << endl;

}

/// using recersion stack to reverse the single linked list
void displayRec(node *head) {
    /**
     * Base Case : when node is null or head is null return (break recersion)
     * Body : else call for the next node in the linked list until next node is null
    */
    if(head == NULL) return;
    displayRec(head->next);
    cout << head->data << "->";
}

int main() {

    cout << "------ Using stack data strcuture ------- " << endl;
    cout << "Test Case 1 :" << endl;
    node *head = createList(5);
    print(head);
    displayRevStack(head);

    cout << "Test Case 2 :" << endl;
    node *head2 = createList(1);
    print(head2);
    displayRevStack(head2);

    cout << "------ Using recersion call stack ------- " << endl;
    cout << "Test Case 1 :" << endl;
    node *head3 = createList(5);
    print(head3);
    displayRec(head3);
    cout << "NULL" << endl;

    cout << "Test Case 2 :" << endl;
    node *head4 = createList(1);
    print(head4);
    displayRec(head4);
    cout << "NULL" << endl;

 return 0;
}
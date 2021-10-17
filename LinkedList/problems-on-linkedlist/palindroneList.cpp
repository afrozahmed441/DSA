#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   :  Given a linked list, check whether it is a palindrone 

- input     :  head of the linked list
- output    :  true or false 

- Example Test Case:
  i/o  : 1->2->3->2->1
  o/p  : true

  i/o  : 1->2->3
  o/p  : false

  i/o  : 2->3->2
  o/p  : 2->3->2

*/
struct node {
    int data;
    node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

void print(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/// --------------------------------- Main Logic ----------------------------------
/// using stack data structure
bool isPalindrone(node *head) {

    if(head == NULL) return true;
    else {
        stack <int> st;
        node *temp = head;
        while(temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while(!st.empty()) {
            if(temp->data != st.top()) return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }

}

/// reverse linked list 
node *reverseList(node *head) {
    if(head == NULL || head->next == NULL) return head;

    node *newHead = reverseList(head->next);
    node *rTail = head->next;
    rTail->next = head;
    head->next = NULL;
    return newHead;
}

/// using reverse, and reverse the second half of the linked list 
bool isPalindroneL(node *head) {
    if(head == NULL) return true;

    /// find the middle 
    node *s = head, *f = head;
    while(f->next != NULL && f->next->next != NULL) {
        s = s->next;
        f = f->next->next;
    }
    /// reverse the second half of the linked list
    node *rev = reverseList(s->next);
    node *cur = head;
    
    /// compare the second half of the linked list and first half 
    while(rev != NULL) {
        if(rev->data != cur->data) return false;
        rev = rev->next;
        cur = cur->next;
    }

    return true;
}

int main() {

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1);

    cout << "------------------ Using stack method -------------------------" << endl;
    cout << "[Linked List] : ";
    print(head);
    cout << "is Palindrone : " << isPalindrone(head) << endl;
    cout << endl;

    cout << "------------------ Using reverse method -------------------------" << endl;
    cout << "[Linked List] : ";
    print(head);
    cout << "is Palindrone : " << isPalindroneL(head) << endl;
    cout << endl;

 return 0;
}
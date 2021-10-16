#include <iostream>
#include <unordered_map>
using namespace std;

/*

- Problem   :  Given a linked list with some random pointers, clone the given linked list

- input     : head of the linked list
- output    : clone linked list

- Example Test Cases 
  i/o : data = 1, random = 5
        data = 2, random = 3
        data = 3, random = 2
        data = 4, random = 5
        data = 5, random = 1

  o/p : clone linked list 
        data = 1, random = 5
        data = 2, random = 3
        data = 3, random = 2
        data = 4, random = 5
        data = 5, random = 1

*/

/// node structure
struct node {
    int data;
    node *next;
    node *random;

    node(int x) {
        data = x;
        next = random = NULL;
    }

};

node *createRandomList(int n){
    node *head = new node(1);
    node *tail = head;

    for(int i = 2; i <= n; i++) {
        node *n = new node(i);
        tail->next = n;
        tail = tail->next;
    }

    /// random pointers
    node *temp = head;
    while(temp->next != NULL) {
        temp->random = temp->next;
        temp = temp->next;
    }
    temp->random = head;

  return head;
}

void printRandomList(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << "data : " << temp->data << " random : " << temp->random->data << endl;
        temp = temp->next;
    }
}

/// --------------------------- Main Logic -------------------------------------

/// using hash map to clone
node *cloneH(node *head) {
    if(head == NULL) return head;
    
    unordered_map<node *, node *> m;
    for(node *temp = head; temp != NULL; temp = temp->next)
        m[temp] = new node(temp->data);
    
    for(node *temp = head; temp != NULL; temp = temp->next) {
        node *cloneNode = m[temp];
        cloneNode->next = m[temp->next];
        cloneNode->random = m[temp->random];
    }
    return m[head];
}

/// using links in the linked list
node *clone(node *head) {

    // clone the nodes jst next to the original nodes in the linked list
    for(node *temp = head; temp != NULL; ) {
        node *next = temp->next;
        temp->next = new node(temp->data);
        temp->next->next = next;
        temp = next;
    }

    /// random pointer
    for(node *temp = head; temp != NULL; temp = temp->next->next) {
        temp->next->random = ((temp->random != NULL) ? temp->random->next : NULL);
    }

    /// separate original and clone linked lists
    node *ori = head, *cop = head->next, *cloneHead = head->next;
    while(ori != NULL && cop != NULL) {

        ori->next = ((ori->next)? ori->next->next : ori->next);
        cop->next = ((cop->next)? cop->next->next : cop->next);

        ori = ori->next;
        cop = cop->next;

    }
    return cloneHead;
}

/// int main
int main() {

    cout << "---------------------- Using Hashsing Method ---------------------" << endl;
    node *head = createRandomList(5);
    cout << "[Linked List] : " << endl;
    printRandomList(head);
    node *clone = cloneH(head);
    cout << "[Clone Linked List] : " << endl;
    printRandomList(clone);
    cout << endl;

    cout << "---------------------- Using Links Method ---------------------" << endl;
    node *head2 = createRandomList(5);
    cout << "[Linked List] : " << endl;
    printRandomList(head2);
    node *clone2 = cloneH(head2);
    cout << "[Clone Linked List] : " << endl;
    printRandomList(clone2);
    cout << endl;

    return 0;
}
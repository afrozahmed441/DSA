#include <iostream>
#include <unordered_set>
using namespace std;

/*

- Problem   : Given two Linked Lists, find the intersection point of two linked lists

- input     : head pointers of two linked lists
- output    : intersection node data

- Example Test Cases:
  i/o : 1->2->3->4->5
        2->3->4->5
  o/p : 3

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

/// -------------------------------- Main Logic ----------------------------------

/// using hashing method
/// Time Complexcity  :  O(N), where N is lenght of the linked list inserted into unordered_set
/// Auxiliary Space   :  O(N), where N is lenght of the linked list
int findIntersectionNode(node *h1, node *h2) {
    unordered_set<node *> s;
    node *t1 = h1, *t2 = h2;
    while(t1 != NULL) {
        s.insert(t1);
        t1 = t1->next;
    }
    while(t2 != NULL) {
        if(s.find(t2) != s.end()) return t2->data;
        t2 = t2->next;
    }
    return -1;
}

/// using difference of node count
/// Time Complexcity  :  O(N+M), where N and M are size of both linked lists
/// Auxiliary Space   :  O(1)
/**
 * Count the number of nodes in linked list one, let it be c1
 * Count the number of nodes in linked list two, let it be c2
 * Find the difference of the difference, let d be the difference 
 * Move the bigger linked list d nodes a ahead from starting node 
 * Then travel the nodes in both linked lists in parallel.
*/


/// using fast and slow pointers
/// Time Complexcity  :  O(M+N)
/// Auxiliary Space   :  O(1)
int findIntersectionNodeFS(node *h1, node *h2) {
    node *t1 = h1, *t2 = h2;
    
    if(t1 == NULL || t2 == NULL) return -1;
    else {
        while(t1 != t2) {
            if(t1 == NULL) t1 = h2;
            else t1 = t1->next;

            if(t2 == NULL) t2 = h1;
            else t2 = t2->next;
        }
        return t1->data;
    }
    return -1;
}

int main() {

    /// Creating a random linked lists with a intersection node
    node* newNode;
    node* head1 = new node(10);
    node* head2 = new node(3);
    newNode = new node(6);
    head2->next = newNode;
    newNode = new node(9);
    head2->next->next = newNode;
    newNode = new node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new node(30);
    head1->next->next = newNode;
    head1->next->next->next = NULL;

    cout << "------------------ Using Hashing method ------------------------" << endl;
    cout << "[Linked List 1] : ";
    print(head1);
    cout << "[Linked List 2] : ";
    print(head2);
    cout << "[Intersection Node is] : " << findIntersectionNode(head1, head2) << endl;
    cout << endl;

    cout << "------------------ Using Fast and Slow method ------------------------" << endl;
    cout << "[Linked List 1] : ";
    print(head1);
    cout << "[Linked List 2] : ";
    print(head2);
    cout << "[Intersection Node is] : " << findIntersectionNodeFS(head1, head2) << endl;
    cout << endl;


 return 0;
}
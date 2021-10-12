#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    head = NULL;
}

/// createNewNode Functions creates a new node and sets data , prev and next and returns the new node
node *DoubleLinkedList::createNewNode(int data) {
    node *newNode = new node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
   return newNode;
}

/// insertAtBegin Function, insert the data at the head of Double Linked List
void DoubleLinkedList::insertAtBegin(int data) { 
    node *newNode = createNewNode(data);
    if(head == NULL) head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

/// insertAtEnd Function, insert the data at the end(tail) of Double Linked List
void DoubleLinkedList::insertAtEnd(int data) {
    node *newNode = createNewNode(data);
    if(head == NULL) head = newNode;
    else {
        node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

/// insert Function, can insert node with given data at given position (pos) in the double linked list
void DoubleLinkedList::insert(int data, int pos) {
    node *newNode = createNewNode(data);
    if(pos == 1 && head != NULL) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if(head == NULL && pos == 1) head = newNode; 
    else {
        int c = 1;
        node *temp = head;
        while(temp != NULL && c != pos-1) {
            temp = temp->next;
            c++;
        }
        if(temp == NULL) return;

        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

/// returns the deleted node data if head is not NULL
/// if head is NULL, then returns -1
int DoubleLinkedList::deleteAtBegin() {
    int data;
    /// no nodes in the double linked list
    if(head == NULL) data = -1;

    /// only one node in the double linked list
    else if(head->next == NULL){
        node *temp = head;
        data = temp->data;
        head = head->next;   /// (NULL)
        delete(temp);
    }

    /// more than one node in the double linked list
    else {
        node *temp = head;
        data = temp->data;
        head = head->next;
        head->prev = NULL;
        delete(temp);
    }
    return data;
}

/// returns the deleted node data if head is not NULL
/// if head is NULL, then returns -1
int DoubleLinkedList::deleteAtEnd() {
    int data;
    /// no nodes in the double linked list
    if(head == NULL) data = -1;

    /// only one node in the linked list
    else if(head->next == NULL){
        node *temp = head;
        data = head->data;
        head = head->next;
        delete(temp);
    }

    /// more than one node in the double linked list
    else {
        node *temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        data = temp->next->data;
        /// for deallocating the space of the node, store the address of the node
        node *n = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete(n);
    }
    return data;
}

/// Delete Node Function, deletes the node at a given position in the double linked list and returns the data of the node
/// if the given position is greater than double linked list length, then returns -1
int DoubleLinkedList::deleteNode(int pos) {
    int data;
    if(head == NULL) data = -1;

    else if(pos == 1 ) {
        node *n = head;
        data = head->data;
        head = head->next;
        delete(n);
    }
    
    else {
        int c = 1;
        node *temp = head;
        while(temp != NULL && c != pos-1) {
            temp = temp->next;
            c++;
        }
        
        if(temp == NULL) return -1;

        node *n = temp->next;
        data = n->data;
        n->prev = NULL;
        temp->next = n->next;
        n->next = NULL;
        delete(n);
    }
    return data;
}

/// Search Function, finds the node with given data in the double linked list. 
/// if the node is present in the double linked list returns position of the node in the linked list, else returns -1
int DoubleLinkedList::search(int data){
        node *temp = head;
        int pos = 1;
        while(temp != NULL){
            if(temp->data == data) return pos;
            else {
                pos++;
                temp = temp->next;
            }
        }
    return -1;
}

void DoubleLinkedList::printDList() {
    if(head == NULL) cout << "Double Linked List is Empty" << endl;
    else {
        /// for reverse travel 
        bool canRev = false;
        node *temp = head;
        cout << "[Normal order] : ";
        while(temp->next != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
            canRev = true;
        }
        cout << temp->data << endl;

        /// printing the double linked list in reverse using the prev pointer
        if(canRev) {
            cout << "[Reverse order] : ";
            while(temp->prev != NULL){
                cout << temp->data << "->";
                temp = temp->prev;
            }
            cout << temp->data << endl;
        }
    }
}
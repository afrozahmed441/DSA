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

void DoubleLinkedList::printDList() {
    if(head == NULL) cout << "Double Linked List is Empty" << endl;
    else {
        node *temp = head;
        cout << "[Normal order] : ";
        while(temp->next != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;

        /// printing the double linked list in reverse using the prev pointer
        cout << "[Reverse order] : ";
        while(temp->prev != NULL){
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << temp->data << endl;
    }
}
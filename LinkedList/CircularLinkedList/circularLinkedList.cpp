#include <iostream>
#include "circularLinkedList.h"
using namespace std;

CircularLinkedList::CircularLinkedList() {
    head = NULL;
    tail = NULL;
}

node *CircularLinkedList::createNewNode(int data) {
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void CircularLinkedList::insertAtBegin(int data) {
    node *newNode = createNewNode(data);
    if(head == NULL) {
        head = newNode;
        tail = head;
        tail->next = head;
    }

    else{
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

}

void CircularLinkedList::insertAtEnd(int data) {
    node *newNode = createNewNode(data);
    if(head == NULL) {
        head = newNode;
        tail = head;
        tail->next = head;
    }

    else{
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

/// insert functions, can insert a node with given data at given position in the circular linked list
void CircularLinkedList::insert(int data, int pos) {
    node *newNode = createNewNode(data);
    /// insert at head
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        /// update the tail to point to updated head
        if(tail == NULL) {
            tail = head;
            tail->next = head;
        }
        else tail->next = head;
    }
    /// insert new to head in the circular linked list
    else if(pos == 2 && head != NULL) {
        newNode->next = head->next;
        head->next = newNode;
    }
    /// insert any where, but not at head or next to the head
    else {
        node *temp = head;
        int c = 1;
        do {
            temp = temp->next;
            c++;
        }while(temp != head && c != pos-1);
    
        if(temp == head) return;

        newNode->next = temp->next;
        temp->next = newNode;
        if(newNode->next == head) tail = newNode;
    }
}

int CircularLinkedList::deleteAtBegin() {
    int data;
    /// no nodes in the circular linked list
    if(head == NULL) data = -1;

    /// only one node in the circular linked list
    else if(head->next == head){
        data = head->data;
        node *temp = head;
        head = NULL;
        tail = NULL;
        delete(temp);
    }

    /// more than one node in the circular linked list
    else {
        node *temp = head;
        data = temp->data;
        head = head->next;
        tail->next = head;
        delete(temp);
    }
    return data;
}

int CircularLinkedList::deleteAtEnd() {
    int data;
    /// no nodes in the circular linked list
    if(head == NULL) data = -1;
    
    /// only one node in the circular linked list
    else if(head->next == head) {
        node *temp = head;
        data = temp->data;
        head = NULL;
        tail = NULL;
        delete(temp);
    }
    /// more than one node in the circular linked list
    else {
        node *temp = head;
        while(temp->next->next != head) temp = temp->next;
        node *n = temp->next;
        data = n->data;
        temp->next = head;
        tail = temp;
        delete(n);
    }
    return data;
}

/// Delete Node Function, delete a node at given position in the circular linked list
int CircularLinkedList::deleteNode(int pos) {
    int data;
    /// no nodes in the circular linked list
    if(head == NULL) data = -1;

    /// delete head node 
    else if(pos == 1) {
        node *n = head;
        data = head->data;
        if(head->next == head){
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            tail->next = head;
        }
        delete(n);
    }

    /// more than one node, and deleting the second node
    else if(pos == 2 && head != NULL && head->next != head) {
        node *n = head->next;
        data = n->data;
        head->next = head->next->next;
        delete(n);
    } 

    else {
        node *temp = head;
        int c = 1;

        do {
            temp = temp->next;
            c++;
        }while(c != pos - 1 && temp != head);

        if (temp == head) return -1;

        node *n = temp->next;
        data = n->data;
        temp->next = temp->next->next;
        delete(n);
    }
    return data;
}

/// Search Function, given a data the search function finds a node with given data in the ciruclar linked list
/// if the node is present in the circular linked list then it returns the position of the node in the circular linked list
/// if the node is not present in the circular linked list then it returns -1
int CircularLinkedList::search(int data) {
        node *temp = head;
        int pos = 1;
        while(temp != NULL) {
            if(temp->data == data) return pos;
            else {
                pos++;
                temp = temp->next;
            }
        }
        return -1;
}

void CircularLinkedList::printCList() { 
    if(head == NULL) cout << "Circular Linked List is Empty" << endl;
    else {
        node *temp = head;
        while(temp->next != head){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}
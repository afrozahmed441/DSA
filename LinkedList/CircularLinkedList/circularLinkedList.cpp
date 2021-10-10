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
        head->next = head;
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
        head->next = head;
    }

    else{
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
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
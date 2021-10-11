#include <iostream>
#include "singleLinkedList.h"
using namespace std;

singleLinkedList::singleLinkedList(){
    head = NULL;
}

node *singleLinkedList::createNewNode(int data){
    node *n = new node(data);
  return n;
}

void singleLinkedList::insertAtBegin(int data){
    
    node *newNode = createNewNode(data);

    if(head == NULL) head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }

}

void singleLinkedList::insertAtEnd(int data){
    node *newNode = createNewNode(data);
    if(head == NULL) head = newNode;
    else {
        node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

/// insert a node with given data at give pos in the linked list
void singleLinkedList::insert(int pos, int data){
    node *newNode = createNewNode(data);
    if(pos == 1){
        newNode->next = head;
        head = newNode;
    }

    else {
        node *temp = head;
        int c = 1;
        while(temp != NULL && c != pos-1) {
            temp = temp->next;
            c++;
        }
        
        if(temp == NULL) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/// returns the deleted node data, if head is not null
/// if head is null then returns -1
int singleLinkedList::deleteAtBegin(){
    int data;
    /// no nodes in the linked list
    if(head == NULL) data = -1;
    /// one or more than one node in the linked list (in this case we also cover when there is only one node in the linked list)
    else {
        node *temp = head;
        data = temp->data;
        head = head->next;
        delete(temp);
    }
    return data;
}


/// returns the deleted node data, if head is not null
/// if head is null then returns -1
int singleLinkedList::deleteAtEnd(){
    int data;
    /// no nodes in the linked list
    if(head == NULL) data = -1;

    /// when there is only one node in the linked list
    if(head->next == NULL) {
        node *temp = head;
        data = head->data;
        head = head->next;
        delete(temp);
    }
    /// more than one node in the linked list
    else {
        node *temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node *t = temp->next;
        data = t->data;
        temp->next = NULL;
        delete(t);
    }
    return data;
}

void singleLinkedList::printList(){
    if(head == NULL) cout << "Linked List is empty" << endl;
    else {
        node *temp = head;
        while(temp->next != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}
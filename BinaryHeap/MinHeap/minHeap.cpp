#include <iostream>
#include "MinHeap.h"
using namespace std;

/// constructor 
MinHeap::MinHeap(int c) {
    cap = c;
    size = 0;
    arr = new int[c];
}

///get left child index
int MinHeap::getLeftChildInd(int i) { return (2*i+1); }

///get right child index
int MinHeap::getRightChildInd(int i) { return (2*i+2); }

///get parent index
int MinHeap::getParentInd(int i) { return (i-1/2); }

/// insert a node into min heap
/// Algo:
/// insert the new node as the leaf node at the last
/// compare the node with its parent node data
/// if parent node data is greater than the new node data then swap them 
/// and then compare the new node position with its parent 
/// perform the above steps until new node is settled.
void MinHeap::insert(int data) {
    /// check if the min heap is full
    if(size-1 == cap) return;
    /// get the last index
    int i = size;
    /// insert data at last index and increment size
    arr[size++] = data;
    /// compare the new Node and parent node 
    while(i != 0 && arr[getParentInd(i)] > arr[i]) {
        swap(arr[getParentInd(i)], arr[i]);
        i = getParentInd(i);
    }
}


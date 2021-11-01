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
int MinHeap::getParentInd(int i) { return ((i-1)/2); }

/// insert a node into min heap
/// Algo:
/// insert the new node as the leaf node at the last
/// compare the node with its parent node data
/// if parent node data is greater than the new node data then swap them 
/// and then compare the new node position with its parent 
/// perform the above steps until new node is settled.
/// Time Complexcity : O(logN), where N is the size
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

/// Min Heapify recersive
/// Time Complexcity : O(h), h is height
void MinHeap::minHeapify(int i) {
    /// get left child and right child ind
    int l = getLeftChildInd(i), r = getRightChildInd(i);
    /// set smallest as root
    int s = i;
    /// compare the root with left child
    if(l < size && arr[l] < arr[i]) s = l;
    /// compare the root with right child or smallest value
    if(r < size && arr[r] < arr[s]) s = r;
    /// if the smallest is not root node then swap root with smallest 
    /// and pass the index of smallest to minHeapify to recersivly check for it
    if(s != i) {
        swap(arr[i], arr[s]);
        minHeapify(s);
    }
}

/// get Min in Min heap
int MinHeap::getMin() { return arr[0]; }

/// extract Min in Min heap
int MinHeap::extractMin() {
    /// if min heap is empty
    if(size == 0) return -1;
    /// if min heap has only one element
    if(size == 1) {
        size--;
        return arr[0];
    }
    /// more than one element in the min heap
    swap(arr[0], arr[size-1]);
    size--;
    minHeapify(0);
    return arr[size];
}

/// Decrease key 
void MinHeap::decreaseKey(int i, int x) {
    arr[i] = x;
    while( i != 0 && arr[getParentInd(i)] > arr[i]) {
        swap(arr[i], arr[getParentInd(i)]);
        i = getParentInd(i);
    }
}

/// delete 
int MinHeap::deleteKey(int i) {
    int del = arr[i];
    decreaseKey(i, INT_MIN);
    extractMin();
    return del;
}

/// print Min Heap 
void MinHeap::printMinHeap() {
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}
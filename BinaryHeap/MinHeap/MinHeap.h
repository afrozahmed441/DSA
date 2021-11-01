#ifndef _MINHEAP_
#define _MINHEAP_

class MinHeap {
    int size;
    int cap;
    int *arr;

public:
    MinHeap(int);
    int getLeftChildInd(int);
    int getRightChildInd(int);
    int getParentInd(int);
    void insert(int);
    void minHeapify(int);
    int getMin();
    int extractMin();
    void decreaseKey(int, int);
    int deleteKey(int);
    void printMinHeap();
};

#endif
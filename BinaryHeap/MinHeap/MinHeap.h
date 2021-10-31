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
};

#endif
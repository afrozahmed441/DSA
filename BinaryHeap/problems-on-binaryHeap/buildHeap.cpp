#include <iostream>
using namespace std;

/*

Problem     :  Given an random array, rearrange its elements to form min heap

input       :  array 
output      :  array elements rearranged in the form of min heap

*/

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ---------------------- Main Logic ---------------------------------------
void minHeapify(int arr[], int i, int size) {
    /// get left and right child 
    int lv = (2*i+1), rv = (2*i+2);
    int s = i;
    /// compare left child with root 
    if(lv < size && arr[lv] < arr[s]) s = lv;
    /// compare right child with root
    if(rv < size && arr[rv] < arr[s]) s = rv;
    /// if root is not the smallest element
    if(s != i) {
        swap(arr[i], arr[s]);
        minHeapify(arr, s, size);
    } 
}
void buildMinHeap(int arr[], int n) {
    /// check internal nodes are min heap or not 
    for(int i = (n-2)/2; i>=0; i--) minHeapify(arr, i, n);
}

int main() {

    int arr[] {10, 5, 20, 2, 4, 8};
    int n {6};
    cout << "Before Build : ";
    printArr(arr, n);
    cout << "After Build : ";
    buildMinHeap(arr, n);
    printArr(arr, n);
}
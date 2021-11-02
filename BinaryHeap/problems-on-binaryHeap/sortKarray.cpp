#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

- Problem   : Given a k-sorted array, sort the array
              k-sorted array means that each element in the array is far from its correct position by k+i or k-i, i is index of element

- input     : K-sorted array 
- output    : sorted array 

*/

/// print array elements 
void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

/// --------------------------------- Main Logic ----------------------------------
/// Time Complexcity : O(n+klogk)
/// Auxiliary Space  : O(k)
void kSort(int arr[], int n, int k) {
    /// create a min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i <= k; i++) {
        pq.push(arr[i]);
    }
    /// insert the sorted elements into array and remove them 
    /// insert new elements into min heap
    int ind = 0;
    for(int i = k+1; i < n; i++) {
        arr[ind++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    /// until min heap is empty
    while(!pq.empty()) {
        arr[ind++] = pq.top();
        pq.pop();
    }

}

int main() {
    int arr[] {9, 8, 7, 18, 19, 17};
    int k {2};
    int n {6};
    cout << "Before sort : ";
    printArr(arr, n);
    cout << "After sort : ";
    kSort(arr, n, k);
    printArr(arr, n); 
 
 return 0;
}
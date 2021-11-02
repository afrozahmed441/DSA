#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

- Problem   : Given a array of elements and a value k, print k largest elements from array 

- input     : Array and value k
- output    : k largest elements from the array

*/


/// -------------------------------------- Main Logic -----------------------------
/// using max heap 
/// Time Complexcity : O(n+klogn)
/// Auxiliary Space  : O(N)
/// N is number of elements and k is give value
void kLargestMaxHeap(int arr[], int n, int k) {
    /// create max heap with given array 
    priority_queue<int> pq(arr, arr+n);
    int c = 0;
    while(!pq.empty() && c < k) {
        cout << pq.top() << " ";
        pq.pop();
        ++c;
    }
}

/// using min heap 
/// Time Complexcity : O(k+(n-k)logk)
/// Auxiliary Space  : O(k)
void kLargestMinHeap(int arr[], int n, int k) {
    /// create a min heap with first k elements in the array 
    priority_queue<int, vector<int>, greater<int>> pq;
    /// push first k elements in array to min heap 
    /// build min heap with first k elements, takes O(k) time
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    /// process next elements
    for(int i = k; i < n; i++) {
        /// if the top of the min heap is smaller than current element then 
        /// pop top element and insert current element into min heap.
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        } else {
            /// if the top of the min heap is greater than current element then 
            /// just continue iterating through array elements.
            continue;
        }
    }

    /// print min heap elements
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

}

int main() {
 
    int arr[] {5, 15, 10, 20, 8};
    int n {5};
    int k {2};
    cout << "----------------- Max Heap ------------------" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "First " << k << " Largest elements : ";
    kLargestMaxHeap(arr, n, k);
    cout << endl;

    cout << "----------------- Min Heap ------------------" << endl;
    cout << "Test Case 1 : " << endl;
    cout << "First " << k << " Largest elements : ";
    kLargestMinHeap(arr, n, k);
    cout << endl;

 return 0;
}
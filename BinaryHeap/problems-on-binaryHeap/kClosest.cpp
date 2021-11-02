#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*

- Problem   :  Given a array of elements, k and x, find the k closest values of x in the given array 

- input     : Array of elements, x and k
- output    : K closest elements of x in array 

*/

/// -------------------------------- Main Logic ----------------------------------
void kClosest(int arr[], int n, int k, int x) {
    priority_queue<pair<int, int>> pq;
    /// insert first k elements into max heap 
    /// with the abs difference between x and current element and the index of element
    for(int i = 0; i < k; i++) {
        pq.push({abs(arr[i]- x), i});
    }

    /// process next elements 
    /// compare the first k elements abs difference with next elements abs difference of x
    /// if the new abs difference is less than the top element in max heap then pop it and insert new abs diff and index of element
    for(int i = k; i < n; i++) {
        int diff = abs(arr[i] - x);
        if(pq.top().first > diff) {
            pq.pop();
            pq.push({diff, i});
        }
    }

    /// print the elements in max heap 
    while(!pq.empty()) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }

}

int main() {

    int arr[] {10, 15, 7, 3, 4};
    int n {5};
    int k {2};
    int x {8};

    cout << "RES : ";
    kClosest(arr, n, k, x);
    cout << endl;

 return 0;
}
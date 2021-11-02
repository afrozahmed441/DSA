#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

- Problem   : Given a array of cost of items and a sum, find max number of items that he/she can purchase

- input     : array of item costs, sum 
- output    : max number of items, he/she can purchase using the sum

*/

/// --------------------------------- Main Logic ---------------------------------
int maxItems(int arr[], int n, int sum) {
    /// create a min heap with given array 
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(sum >= pq.top()) {
            sum -= pq.top();
            pq.pop();
            ++res;
        } else {
            break;
        }
    }
 return res;
}


int main() {
 
    int arr[] {1, 12, 5, 111, 200};
    int n {5};
    int sum {10};

    cout << "Test Case 1 :" << endl;
    cout << "Max number of items with sum " << sum << " is : " << maxItems(arr, n, sum) << endl;
    cout << endl;

    int arr2[] {20, 10, 5, 30, 100};
    int n2 {5};
    int sum2 {35};
    cout << "Test Case 2 :" << endl;
    cout << "Max number of items with sum " << sum2 << " is : " << maxItems(arr2, n2, sum2) << endl;
    cout << endl;

  return 0;
}
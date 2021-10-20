#include <iostream>
#include <stack>
using namespace std;

/*
- Problem   : Given a array of elements find the closest next greater element for the current element

- input     : array of elements
- output    : next greater element 

- Example Test Case
  i/o : {5, 15, 10, 8, 6,  12,  9,  18}
  o/p : 15  18  12  12  12  18  18  -1
 
  i/o : {10, 15, 20, 25}
  o/p : 15   20  25  -1

  i/o : {25, 20, 15, 10}
  o/p :  -1  -1  -1  -1

*/

//// print the array elements function
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ----------------------------- Main Logic ------------------------------------

/// Naive Solution
/// Time Complexcity : O(N^2) where N is number of elements in the array
/// Auxiliary Space  : O(1)
void nextGreaterNaive(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int j;
        for(j = i+1; j < n; j++) {
            if(arr[j] > arr[i]) {
                cout << arr[j] << " ";
                break;
            }
        }

        if(j == n) cout << -1 << " ";

    }
}

/// Efficient Solution
/// Time Complexcity : O(N), where N is number of elements in the array
/// Auxiliary Space : O(N), where N is number of elements in the array
void nextGreater(int arr[], int n) {
    stack <int> st;
    stack <int> res;
    res.push(-1);
    st.push(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        int r = ((st.empty()) ? -1 : st.top());
        res.push(r);
        st.push(arr[i]);
    }

    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }

}

int main() {

    cout << "------------------- Naive Solution ------------------------ " << endl;
    cout << "Test Case 1 : " << endl;
    int arr[] = {5, 15, 10, 8, 6,  12,  9,  18};
    int size = 8;
    cout << "[arr] : ";
    print(arr, size);
    cout << "[res] : ";
    nextGreaterNaive(arr, size);
    cout << endl << endl;

    cout << "Test Case 2 : " << endl;
    int arr2[] = {10, 15, 20, 25};
    int size2 = 4;
    cout << "[arr] : ";
    print(arr2, size2);
    cout << "[res] : ";
    nextGreaterNaive(arr2, size2);
    cout << endl << endl;

    cout << "Test Case 3 : " << endl;
    int arr3[] = {25, 20, 15, 10};
    int size3 = 4;
    cout << "[arr] : ";
    print(arr3, size3);
    cout << "[res] : ";
    nextGreaterNaive(arr3, size3);
    cout << endl << endl;

    cout << "------------------- Efficient Solution ------------------------ " << endl;
    cout << "Test Case 1 : " << endl;
    cout << "[arr] : ";
    print(arr, size);
    cout << "[res] : ";
    nextGreater(arr, size);
    cout << endl << endl;

    cout << "Test Case 2 : " << endl;
    cout << "[arr] : ";
    print(arr2, size2);
    cout << "[res] : ";
    nextGreater(arr2, size2);
    cout << endl << endl;

    cout << "Test Case 3 : " << endl;
    cout << "[arr] : ";
    print(arr3, size3);
    cout << "[res] : ";
    nextGreater(arr3, size3);
    cout << endl << endl;

  return 0;
}
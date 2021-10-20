#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   : Given a array of elements find the closest greater element on the left side of the current element, if there is no greater element then print -1

- intput    : array of elements
- output    : closest greater element on the left of the current element

- Example Test cases:
  i/o : {15, 10, 18, 12, 4,  6,  2,  8}
  o/p : -1   15  -1  18  12  12  6   12

  i/o : {8, 10, 12}
  o/p : -1  -1  -1

  i/o : {12, 10,  8}
  o/p : -1   12  10 

*/

/// print array elements 
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ---------------------------------- Main Logic ------------------------------

/// Naive Solution 
/// Time Complexcity : O(N^2), where N is number of elements in the array
/// Auxiliary Space  : O(1)
void printPrevGreaterNaive(int arr[], int n) {
    
    cout << -1 << " ";
    for(int i = 1; i < n; i++) {
        int j;
        for(j = i-1; j>=0; j--) {
            if(arr[j] > arr[i]) {
                cout << arr[j] << " ";
                break;
            }
        }

        if(j == -1) cout << -1 << " ";

    }
    cout << endl;
}

/// Efficient Solution 
/// Time Complexcity : O(N), where N is number of elements in the array
/// Auxiliary Space  : O(N), where N is number of elements in the array 
void printPrevGreater(int arr[], int n) {
    stack<int> st;
    st.push(arr[0]);
    cout << -1 << " ";
    for(int i = 1; i < n; i++) {

        while(!st.empty() && st.top() <= arr[i]) st.pop();
        
        cout << ((st.empty()) ? -1 : st.top()) <<  " ";
        st.push(arr[i]);
    }
}

int main() {

    cout << "------------------- Naive Solution ------------------------- " << endl;
    cout << "Test Case 1 : " << endl;
    int arr[] = {15, 10, 18, 12, 4,  6,  2,  8};
    int size = 8;
    cout << "[arr] : ";
    print(arr, size);
    cout << "[res] : ";
    printPrevGreaterNaive(arr, size);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    int arr2[] = {8, 10, 12};
    int size2 = 3;
    cout << "[arr] : ";
    print(arr2, size2);
    cout << "[res] : ";
    printPrevGreaterNaive(arr2, size2);
    cout << endl;

    cout << "Test Case 3 : " << endl;
    int arr3[] = {12, 10, 8};
    int size3 = 3;
    cout << "[arr] : ";
    print(arr3, size3);
    cout << "[res] : ";
    printPrevGreaterNaive(arr3, size3);
    cout << endl;

    cout <<"--------------------- Efficient Solution -------------------------- " << endl;
    cout << "Test Case 1 : " << endl;
    cout << "[arr] : ";
    print(arr, size);
    cout << "[res] : ";
    printPrevGreater(arr, size);
    cout << endl << endl;

    cout << "Test Case 2 : " << endl;
    cout << "[arr] : ";
    print(arr2, size2);
    cout << "[res] : ";
    printPrevGreater(arr2, size2);
    cout << endl << endl;

    cout << "Test Case 3 : " << endl;
    cout << "[arr] : ";
    print(arr3, size3);
    cout << "[res] : ";
    printPrevGreater(arr3, size3);
    cout << endl << endl;
 
 return 0;
}
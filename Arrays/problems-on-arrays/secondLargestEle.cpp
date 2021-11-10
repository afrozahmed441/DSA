#include <iostream>
using namespace std;

/*

- Problem   : Given a array, find the second largest element in the array 

- input     : array 
- output    : second largest element in the array

- Example Test Cases

  o/i : [1, 5, 2, 4]
  o/p : 4

  o/i : [10, 10, 5, 8]
  o/p : 8

  o/i : [1]
  o/p : -1

*/

////// --------------------------------- Main Logic --------------------------------

/// #Method - 1 (sorting)
/// check array length is greater than one 
/// else print -1
/// if greater than one sort the array 
/// and print element at second index
/// Time Complexicty : O(NlogN), where N is number of elements in the array

//// #Method-2 
//// 1. iterate through the array 
//// 2. while iterating through array check for the largest and second largest at same time.
//// Time Complexcity : O(N), where N is number of elements 

/// #Method - 2 
int secondLargestEle(int arr[], int n) {
    int l = arr[0], sl = -1;
    for(int i = 1; i < n; i++) {
        if(l < arr[i]) {
            sl = l;
            l = arr[i];
        } else if(l != arr[i]) {
            if(sl == -1 || sl < arr[i]) sl = arr[i];
        }
    }
  return sl;
} 


int main() {
    int arr[] {1, 5, 2, 4};
    int s {4};
    cout << "Test Case 1 : " << endl;
    cout << "Second Largest Element : " << secondLargestEle(arr, s);
    cout << endl;

    int arr2[] {10, 10, 5, 8};
    int s2 {4};
    cout << "Test Case 2 : " << endl;
    cout << "Second Largest Element : " << secondLargestEle(arr2, s2);
    cout << endl;

    int arr3[] {1};
    int s3 {1};
    cout << "Test Case 3 : " << endl;
    cout << "Second Largest Element : " << secondLargestEle(arr3, s3);
    cout << endl;

 return 0;
}
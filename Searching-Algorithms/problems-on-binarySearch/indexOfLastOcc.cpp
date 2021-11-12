#include <iostream>
using namespace std;


/*

- Problem   : Given a sorted array, find the last occurance of given number in the array

- input     : Sorted array 
- ouput     : last index of the given number in the array

*/

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ----------------------------------- Main Logic -------------------------------
/// Algo : 
/// Using binray Search 
/// Time Complexity : O(LogN), where N is number of elements in the array 
int lastOccurance(int arr[], int n, int ele) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        /// if mid is less than ele
        if(arr[mid] < ele) low = mid+1;
        /// if mid is greater than ele
        else if(arr[mid] > ele) high = mid-1;
        /// if mid is equal
        else {
            if(mid == n-1 || arr[mid+1] != ele) return mid;
            else low = mid + 1; 
        }
    } 
  return -1;
}


int main() {

    int arr[] {1, 2, 3, 4, 4};
    int size {5};
    int ele {4};

    cout << "Test Case 1 : " << endl;
    cout << "Array : ";
    printArray(arr, size);
    cout << "Last Occurance of " << ele << " index: " << lastOccurance(arr, size, ele) << endl;
    cout << endl;

    int arr2[] {1, 2, 3, 3, 3};
    int size2  {5};
    int ele2 {3};
    cout << "Test Case 2 : " << endl;
    cout << "Array : ";
    printArray(arr2, size2); 
    cout << "Last Occurance of " << ele2 << " index: " << lastOccurance(arr2, size2, ele2) << endl;
    cout << endl;

    int arr3[] {1, 2, 3};
    int size3 {3};
    int ele3 {4};
    cout << "Test Case 3 : " << endl;
    cout << "Array : ";
    printArray(arr3, size3);
    cout << "Last Occurance of " << ele3 << " index: " << lastOccurance(arr3, size3, ele3) << endl;
    cout << endl;

 return 0;
}
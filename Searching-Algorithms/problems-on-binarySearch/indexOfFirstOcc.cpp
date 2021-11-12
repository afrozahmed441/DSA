#include <iostream>
using namespace std;

/*

- Problem   : Given an array sorted, find the index of first occurance of given number in the array in O(logN) time Complexity 

- input     : sorted array 
- ouput     : index of first occurance of the given number in the array 

*/

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ---------------------------- Main logic ----------------------------------
/// Algo : 
/// Using Binary Search
/// modify the binary search to check for first occurance of give number
int firstOccurance(int arr[], int n, int ele) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        /// if mid is greater than ele
        if(arr[mid] > ele) high = mid - 1;
        /// if mid is less than ele
        else if(arr[mid] < ele) low = mid + 1;
        /// if mid is equal 
        else {
            if(mid == 0 || arr[mid-1] != ele) return mid;
            else high = mid - 1;
        }
    }
  return -1;
} 

int main() {
    
    int arr[] {15, 15, 15};
    int size {3};
    int ele {15};
    cout << "Test Case 1 : " << endl;
    cout << "Array : ";
    printArray(arr, size);
    cout << "First Occurance of " << ele << " index : " << firstOccurance(arr, size, ele) << endl;
    cout << endl;

    int arr2[] {10, 20, 30};
    int size2 {3};
    int ele2 {15};
    cout << "Test Case 2 : " << endl;
    cout << "Array : ";
    printArray(arr2, size2);
    cout << "First Occurance of " << ele2 << " index : " << firstOccurance(arr2, size2, ele2) << endl;

 return 0;
}
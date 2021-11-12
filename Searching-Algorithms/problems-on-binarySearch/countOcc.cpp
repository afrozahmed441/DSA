#include <iostream>
using namespace std;

/*

- Problem   : Given a sorted array, find the number of times a given number occures in the array

- input     : sorted array
- output    : count of occurances of given number in the array

*/

/// print array 
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

/// find first occurance of element in the array
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

/// find the last occurance of element in the array 
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

//// ------------------------------- Main Logic ----------------------------------

int countOccurances(int arr[], int n, int ele) {
    int fOcc = firstOccurance(arr, n, ele);
    if(fOcc == -1) return 0;
    else return(lastOccurance(arr, n, ele) - fOcc + 1);
}

int main() {

    int arr[] {1, 2, 2, 2, 3, 4, 5};
    int size {7};
    int ele {2};
    cout << "Test Case 1 : " << endl;
    cout << "Array : ";
    printArray(arr, size);
    cout << "Frequency of " << ele << " in array is : " << countOccurances(arr, size, ele);
    cout << endl;

    int arr2[] {1, 2, 3, 4, 5};
    int size2 {5};
    int ele2 {3};
    cout << "Test Case 2 : " << endl;
    cout << "Array : ";
    printArray(arr2, size2);
    cout << "Frequency of " << ele2 << " in array is : " << countOccurances(arr2, size2, ele2);
    cout << endl;

    int arr3[] {1, 2, 3};
    int size3 {3};
    int ele3 {4};
    cout << "Test Case 3 : " << endl;
    cout << "Array : ";
    printArray(arr3, size3);
    cout << "Frequency of " << ele3 << " in array is : " << countOccurances(arr3, size3, ele3);
    cout << endl;

 return 0;
}
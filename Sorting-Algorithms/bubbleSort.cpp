#include <iostream>
using namespace std;

/*

/// Bubble Sort
/// Bubble Sort is a sorting algorithm, in which we compare the adjacent elements and swaping them if they are not in correct position
/// Best Case and Worst Case Time Complexcity : O(N^2), where N is number of elements in the array
/// Auxiliary Space : O(1) 
/// It is Stable and In Place sorting algorithm

*/

void bubbleSort(int arr[], int n){

    /// in each iteration of i, the largest element in the array is placed at its correct position in array
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            /// compare adjacent element in the array
            /// if they are not in correct position then swap
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }

}

void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr[] {10, 2, 3, 5, 1, 6, 7, 9, 8, 4};
    int n {10};
    
    cout << "[Before Sorting] : ";
    display(arr, n);
    bubbleSort(arr, n);
    cout << "[After Sorting] : ";
    display(arr, n);

 return 0;
}
#include <iostream>
using namespace std;

/*

/// Selection Sort
/// In Selection Sort in each iteration we find the ith minimum element(in ascending order) in the array and moved to its correct position

/// Best Case and Worst Case Time Complexcity : O(N^2), where N is number of elements in the array
/// Auxiliary Space : O(1)
/// It is in-place , default implementation is not stable
/// And It does exactly O(N) swaps to sort the array, Where N is number of elements in the array


*/

/// Selection Sort Function
void selectionSort(int arr[], int n){

    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            /// Select the ith minimum element in each loop 
            if(arr[min] > arr[j]) min = j; 
        }
        /// place it in its correct position 
        swap(arr[min], arr[i]);
    }

}

/// display function
void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){

    int arr[] {2, 3, 5, 8, 9, 1, 4, 10, 7, 6};
    int n {10};

    cout << "[Before Sorting] : ";
    display(arr, n);
    cout << "[After Sorting] : ";
    selectionSort(arr, n);
    display(arr, n);


}
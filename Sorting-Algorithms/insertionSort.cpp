#include <iostream>
using namespace std;

/*

/// Insertion Sort
/// In insertion sort, the array is splited into two halfs virtually, one half is sorted and another half is unsorted

/// Algo :
/// 1. start iterating from the second element in the array
/// 2. we store the current element in a variable (k in our program)
/// 3. we compare the before element(predecessor) with the current element 
/// 4. if current element is smaller than its predecessor then we move the predecessor one position up in the array
/// 5. repeat 3 and 4 steps until the current element is greater than its predecessor
/// 6. and place the current element in the correct position.

/// Best Case Time Complexcity : O(N), Where N is number of elements in the array
/// Worst Case Time Comlexcity : O(N^2), where N is number of elements in the array
/// Auxiliary Space : O(1)

/// Best Case occurs when the array is already sorted
/// It is in-place 

*/

/// insertion sort function
void insertionSort(int arr[], int n){

    for(int i = 1; i < n; i++){
        int k = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > k) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }

}

/// display function
void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}


int main() {

    int arr[] {3, 2, 5, 6, 8, 1, 4, 9, 7, 10};
    int n {10};

    cout << "[Before Sorting] : ";
    display(arr, n);
    insertionSort(arr, n);
    cout << "[After Sorting] : ";
    display(arr, n);

 return 0;
}
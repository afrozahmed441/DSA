#include <iostream>
using namespace std;

/*

/// Quick Sort (Using Lamuto Parition)
/// It is a divide and conqure algorithm
/// we break the array until there is only one element on the both sides of the pivot or only one element

/// Best Case and Average Case Time Complexcity : O(NLogN), where N is number of elements in the array
/// Worst Case Time Complexcity : O(N^2), where N is number of elements in the array
/// Auxiliary Space : O(N), where N is number of elements in the array
/// It is in-place 
/// Partition is key in the quick sort

/// Best Case occurs when we have same number of elements on either sides of the pivot
/// worst Case occurs when the array is sorted, when there is only one element on the one side and other elements on the other side of the pivot


*/

/// Lamuto partition function
/// Algo :
/// 1. Usually Pick the last element in the array as the pivot (lamuto partition)
/// 2. we take a variable i to keep track of the elements that are less or equal to pivot
/// 3. start iterating from the first element in the array, variable j keeps track of the elements we iterated 
/// 4. compare the each element with the pivot 
/// 5. if the element is less than the pivot then increment the i and swap arr[i] and arr[j]
/// 6. repeat 4 and 5 until we reach the pivot element or j is equal to  h-1, where h is index of last element
/// 7. Atlast we place the pivot at the correct position in the array
/// 8. and return the index of the pivot 
/// Note : After partition the elements from 0 to i are less than pivot and elements from i+1 to h greater than or equal to pivot
int lamutoPartition(int arr[], int l, int h){

    int pivot = arr[h];
    int i = l-1;
    for(int j = l; j <= h-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return (i+1);
}

/// quick Sort function (recersive approach)
void quickSort(int arr[], int l, int h){
    if(l < h){
        int p = lamutoPartition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

/// display function
void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr[] {1, 5, 9, 8, 10, 4, 2, 3, 6, 7};
    int n {10};

    cout << "[Before Sorting] : ";
    display(arr, n);
    cout << "[After Sorting] : ";
    quickSort(arr, 0, n-1);
    display(arr, n);

    return 0;
}
#include <iostream>
using namespace std;

/*

/// Quick Sort (using Hoare's Partition)
/// The different between Lamuto and Hoare's is that Hoare's Partition does less swaps compared to lamuto to partition the array
/// And Hoare's does not place the pivot element in the correct place in the array as the lamuto

/// Time Complexcity and Auxiliary Space are same as Quick Sort with Lamuto Partition


*/
/// Hoare's Partition 
/// Algo : 
/// 1. Choose the Pivot as the first element in the array (hoare's partition)
/// 2. we start from the first element in the array and compare the elements with pivot
/// 3. if the pivot is greater than the current element then we increment the i, variable i keeps track of the elements that are less than the pivot
/// 4. In same way we start from the last element in the array and compare the elements with pivot
/// 5. if the pivot is less than the current element then we increment the j, variable j keeps track of the elements that are greater than the pivot
/// 6. if the element is not greater than pivot we don't increment the j
/// 7. we check if i is greater than or equal to j then we stop and return j
/// 8. if not then we swap arr[i] and arr[j]
int hoaresPartition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l-1, j = h+1;
    while(true){
        do{
            i++;
        } while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j) return j;
        swap(arr[i], arr[j]);
    }
    return 0;
}

/// Quick Sort Function (recersive)
void quickSort(int arr[], int l , int h){
    if(l < h){
        int p = hoaresPartition(arr, l, h);
        /// we need to include the pivot, because pivot is not placed in its correct place because we are using hoare's partition
        quickSort(arr, l, p);
        quickSort(arr, p+1, h);
    }
}

/// Display Function
void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}


int main() {

    int arr[] {2, 10, 8, 3, 5, 7, 6, 1, 4, 9};
    int n {10};

    cout << "[Before Sorting] : ";
    display(arr, n);
    cout << "[After Sorting] : ";
    quickSort(arr, 0, n-1);
    display(arr, n);

  return 0;
}
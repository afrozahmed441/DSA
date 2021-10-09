#include <iostream>
using namespace std;

/*

/// Merge Sort (Recuersive Approach also know aslo top-down approach)
/// It is a divide and conquer Algorithm
/// we divide the array until there is only one element 

/// Best Case and Worst Case Time Complexcity :  O(NLogN), where N is number of elements in the array
/// Auxiliary Space : O(N), where N is number of elements in the array
/// It is stable

*/

/// Merge Function
void merge(int arr[], int l, int m, int h){
    /// compute size of two arrays (left and right array)
    int n1 = m - l + 1, n2 = h - m;
    /// create two array
    int arrL[n1], arrR[n2];
    /// storing the elements of left and right array into arrL and arrR
    for(int i = 0; i < n1; i++) arrL[i] = arr[l+i];
    for(int i = 0; i < n2; i++) arrR[i] = arr[m+i+1];

    /// Compare the elements from arrL and arrR and merge them 
    int i = 0, j = 0, k = l;
    /// Compare until both of the arrays are not out of index
    while(i < n1 && j < n2){

        if(arrL[i] <= arrR[j]){ 
            arr[k] = arrL[i]; 
            i++; 
            k++; 
        }
        else { 
            arr[k] = arrR[j]; 
            j++; 
            k++; 
        }

    }

    /// insert the remanining elements of arrL into the array 
    while(i < n1){
        arr[k] = arrL[i];
        i++;
        k++;
    }

   /// insert the remanining elements of arrR into the array 
    while(j < n2){
        arr[k] = arrR[j];
        j++;
        k++;
    }

}

/// The merge Sort Function
void mergeSort(int arr[], int l, int h){
    if(l < h){
        int m = (l+h)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, h);
        merge(arr, l, m, h);
    }

}

/// Display Function
void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){

    int arr[] {3, 1, 10, 5, 2, 4, 6, 8, 9, 7};
    int n {10};

    cout << "[Before Sorting] : ";
    display(arr, n);
    cout << "[After Sorting] : ";
    mergeSort(arr, 0, n-1);
    display(arr, n);
    
    return 0;
}
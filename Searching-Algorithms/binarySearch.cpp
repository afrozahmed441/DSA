#include <iostream>
using namespace std;

/*

/// Binary Search

/// In Binary Search we divide the array into two halfs by comapring the given element with the middle element in the array
/// If the element in the middle is greater than the given element then we search in only left half of the array
/// If the element in the middle is less than the given element then we search in only right half of the array
/// we repeat this process until we find the given element or until the middle element is first and last element in the array to check

/// Best Case Time Complexcity   :  O(1)
/// Worst Case Time Complexcity  :  O(log N), where N is number of elements in array
/// Auxiliary Space : O(1)

/// Best Case Time Complexcity Occurs When element we are searching is present in the middle of the array
/// Worst Case Time Complexcity Occurs When element we are searching is present at the starting or ending of the array

*/

/// Binary Search Function
/// retuns the element index in the array if the element is present
/// return -1 when given element is not present in the array
int binarySearch(int arr[], int size, int ele){

    /// as we find the element we keep track of first and last in the search array
    int f = 0, l = size - 1;

    /// we search the element in the array until the first and last cross each other
    /// when first and last cross each other(means f becomes l and l becomes f) we have searched all the positions were the given element can be
    while(f<=l){

        /// compute the mid of the array 
        int mid = (f+l)/2;

        /// if the mid element is the element we are searching for then return the mid
        if(arr[mid] == ele) return mid;
        /// if the mid element is greater than the given element move towards left half of the array by modifying last (l variable)
        else if(arr[mid] > ele) l = mid - 1;
        /// else if the mid element is less than the given element move towards right half of the array by modifying first (f variable) 
        else f = mid + 1;

    }
    return -1;
}

/// Recusive Binary Seach 
/// It takes Auxiliary Space and bit slower than iterative approach
/// jst in Case you wonder
int recBinarySeach(int arr[], int f, int l, int ele){

    if(f > l) return -1;

    int mid = (f+l)/2;

    if(arr[mid] == ele) return mid;

    else if(arr[mid] > ele) return recBinarySeach(arr, f, mid-1, ele);

    else return recBinarySeach(arr, mid+1, l, ele);

}


int main(){

    int arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n {10};
    int ele {7};

    int ind = binarySearch(arr, n, ele);
    int rind = recBinarySeach(arr, 0, n-1, ele);

    cout << ((ind != -1) ? "[Binary Search] : ele Found" : " [Binary Search] : ele not Found") << endl; 
    cout << ((rind != -1) ? "[Recersive Binary Search] : ele Found" : "[Recersive Binary Search] : ele not Found") << endl;
    
 return 0;
}
#include <iostream>
#include <vector>
using namespace std;

/*

/// Linear Search
/// In linear search we search for element in the array in linear way one by one.
/// Best Case Time Complexcity   : O(1)
/// Worst Case Time Complexcity  : O(N), where N is number of elements in array
/// Auxiliary Space : O(1)

/// Best Case Time Complexcity Occurs when the element we are searching for is at begging of the array
/// Worst Case Time Complexcity Occurs when the element we are searching for is at last or not present in the array


*/

/// Linear Search funtion
/// returns the index of element if element is present in the array
/// if element we are searching for is not in the array then returns -1
int linearSearch(int arr[], int size, int ele){

    for(int i = 0; i < size; i++){

        if(arr[i] == ele) return i;

    }
    return -1;
}

int main(){

    int arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n {10};
    int ele {1};
    int ele2 {10};
    
    /// Best Case
    int ind = linearSearch(arr, n, ele);

    /// Worst Case
    int ind2 = linearSearch(arr, n, ele2);

    cout << ((ind != -1) ? "ele Found" : "ele not Found") << endl;
    cout << ((ind2 != -1) ? "ele2 Found" : "ele2 not Found") << endl;


  return 0;
}
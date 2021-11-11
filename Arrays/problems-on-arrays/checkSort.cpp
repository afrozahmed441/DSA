#include <iostream>
using namespace std;

/*

- Problem   :  Given an array, check if it is sorted 

- input     : an array 
- output    : true or false

*/

//// -------------------------------- Main Logic ------------------------------
bool isSorted(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main() {

    int arr[] {1, 2, 3, 4, 5};
    int size {5};
    cout << "Test Case 1 : " << endl;
    cout << ((isSorted(arr, size))?"Yes":"No") << endl;

    int arr2[] {2, 5, 1, 3, 4};
    int size2 {5};
    cout << "Test Case 2 : " << endl;
    cout << ((isSorted(arr2, size2))?"Yes":"No") << endl;
 
 return 0;
}
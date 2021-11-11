#include <iostream>
using namespace std;

/*

- Problem   : Given an array, reverse the array 

- input     : array 
- output    : reversed array

*/

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

/// --------------------------------- Main Logic ---------------------------------
void reverseArray(int arr[], int n) {
    int f = 0, l = n-1;
    while(f < l) {
        swap(arr[f], arr[l]);
        f++;
        l--;
    }
}

int main() {

    int arr[] {1, 2, 3, 4, 5};
    int size {5};
    cout << "Before reverse : ";
    printArray(arr, size);
    cout << "After reverse : ";
    reverseArray(arr, size);
    printArray(arr, size);
    cout << endl;

 return 0;
}
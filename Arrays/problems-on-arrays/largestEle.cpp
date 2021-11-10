#include <iostream>
using namespace std;

/*

- Problem   : Given an array of elements, find the largest element in the array 

- input     : array 
- output    : largest element in the array 

- Example Test Cases 
  i/o : [1, 44, 15, 23, 50]
  o/p : 50

  i/o : [3, 44, 33, 44, 30]
  o/p : 44

  i/o : [1]
  o/p : 1

*/

/// --------------------------------- Main logic -----------------------------------
int largestEle(int arr[], int n) {
    int largestElement = arr[0];
    for(int i = 1; i < n; i++) {
        if(largestElement < arr[i]) largestElement = arr[i];
    }
    return largestElement;
}

int main() {
    int arr[] {3, 44, 33, 44, 30};
    int s {5};
    cout << "Test Case 1 : " << endl;
    cout << "Largest Element : " << largestEle(arr, s);
    cout << endl;

    int arr2[] {1};
    int s2 {1};
    cout << "Test Case 2 : " << endl;
    cout << "Largest Element : " << largestEle(arr2, s2);
    cout << endl;

 return 0;
}
#include <iostream>
using namespace std;

/*

- Problem    :  Given an array find the leader elements in the array, an element in the array is said to be leader if it is greater than all the elements on its right

- input     : array
- ouput     : leader elements in the array

- Example Test Cases 
- i/o   : [7, 10, 4, 3, 6, 5, 2]
- o/p   : 10 6 5 2

- i/o   : [10, 20, 30]
- o/p   : 30

- i/o   : [30, 20, 10]
- o/p   : 30 20 10

*/

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ------------------------------ Main Logic ------------------------------------
/*
/// Naive Solution : 
/// Time Complexity : O(N^2), where N is number of elements in the array
/// Auxiliary Space : O(1)
*/
void printLeaderElements(int arr[], int n) {

    int cur;
    cout << "Leader elements : ";
    for(int i = 0; i < n; i++) {
        /// keep track of current element in the array
        int flag = 0;
        cur = arr[i];
        for(int j = i+1; j < n; j++) {
            /// check for any element that is greater than or equal to the current element on the right side of the current element
            if(cur <= arr[j]) {
                flag = 1;
                break;
            }
        }

        /// if there is no greater or equal element on the right side then it is a leader element
        if(flag == 0) cout << arr[i] << " ";

    }
    cout << endl;
}

//// Efficient Solution
//// Time Complexity : O(N), where N is number of elements in the array 
//// Auxilary Space  : O(1)
//// Algo :
//// 1. travel the array from the right side
//// 2. keep track of current greater element 
//// 3. if current element is greater element than current element then print the current element
//// 4. and update the greater element
//// 5. repeat above steps until the array traveling is done.
void printLeaderElementsEff(int arr[], int n) {

    int curLed = arr[n-1];
    cout << "Leader elements : ";
    cout << curLed << " ";
    for(int i = n-2; i >= 0; i--) {
        if(curLed < arr[i]) {
            curLed = arr[i];
            cout << curLed << " ";
        }
    }
    cout << endl;
}

/// main 
int main() {

    int arr[] {7, 10, 4, 3, 6, 5, 2};
    int n {7};
    cout << "------------ Naive Solution ------------------ " << endl;
    cout << "Array : ";
    printArray(arr, n);
    cout << "Test Case 1 : " << endl;
    printLeaderElements(arr, n);
    cout << endl;

    cout << "---------------- Efficient Solution ---------------------- " << endl;
    cout << "Array : ";
    printArray(arr, n);
    cout << "Test Case 1 : " << endl; 
    printLeaderElementsEff(arr, n);
    cout << endl;

 return 0;
}
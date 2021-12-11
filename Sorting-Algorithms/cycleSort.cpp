#include <iostream>
#include <vector>
using namespace std;

/**
 * Cycle Sort Algorithm
 * Cycle Sort is a in-place and unstable sorting algorithm.
 * Cycle Sort Worst Time Complexity: O(N^2), where N is number of elements in the array.
 * Auxiliary Space : O(1).
 * Cycle Sort is optimal in terms of number of memory writes to sort the array.
 * For each Element in the array it either writes one time to its correct position or zero times when it is already in correct position. 
 * It is based on the idea of the array to be sorted can be divided into cycles, in each cycle we consider the first element,
 * set it to its correct position and consider the element at that position and place it to correct position and it goes on
 * until all the cycles are done and array is sorted 
 * Cycle sort is also useful to count min number of writes required to sort the array.
 
*/

void printArray(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) cout << arr.at(i) << " ";
    cout << endl;
}

/////// --------------------------------------------- Main Logic ---------------------------------------

int cycleSort(vector<int> &arr) {

    int minWrites = 0;

    for(int cs = 0; cs < arr.size()-1; cs++) {

        /// store current index
        int pos = cs;
        /// store current element
        int item = arr.at(cs);

        /// find number of elements in the array less than current element 
        /// and find correct position of the current element
        for(int i = cs+1; i < arr.size(); i++) 
            if(arr[i] < item) pos++; 
        
        /// if current element is in correct position then continue
        if(pos == cs) continue;

        /// duplicate elements 
        while(arr[pos] == item) pos++;

        /// if not at correct position then set the current element at correct position
        if(pos != cs) {
            swap(arr[pos], item);
            ++minWrites;
        }
        /// continue with other elements in the cycle 
        while(pos != cs) {
            pos = cs;

            for(int i = cs+1; i < arr.size(); i++) 
                if(arr[i] < item) pos++;

            while(arr[pos] == item) pos++;

            if(arr[pos] != item) {
                swap(arr[pos], item);
                ++minWrites;
            }
        }
    }
    return minWrites;
}

/// main function 
int main() {

    vector<int> arr{ 4, 2, 3, 1 };
    cout << "Test Case 1 : " << endl;
    cout << "Before Sort : ";
    printArray(arr);
    cout << "After Sort : ";
    int mw = cycleSort(arr);
    printArray(arr);

    cout << "Min writes required to sort : " << mw << endl;
    

    vector<int> arr2{ 2, 4, 5, 1, 3 };
    cout << "Test Case 2 : " << endl;
    cout << "Before Sort : ";
    printArray(arr2);
    cout << "After Sort : ";
    int mw2 = cycleSort(arr2);
    printArray(arr);

    cout << "Min writes required to sort : " << mw2 << endl;


 return 0;
}
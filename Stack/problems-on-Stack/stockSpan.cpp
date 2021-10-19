#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   :  Given a array of stocks prices, print the number of stocks prices is less than or equal to current stock price in previous days (include the current day)

- input     : array of stock prices
- output    : number of stock prices that are less than or equal to current day stock price (include the current day)

- Example Test Cases:
  i/o : {13, 15, 12, 14, 16, 8, 6, 4, 10, 30}
  o/p :  1    2   1   2   5  1  1  1   4  10

  i/o : {10, 20, 30, 40}
  o/p : 1    2   3   4

  i/o : {40, 50, 60, 70}
  o/p :  1   1   1   1

*/

/// print array 
void print(const int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//// ---------------------------------- Main Logic -------------------------------

/// Naive Solution 
/// Time Complexcity  : O(N^2), where N is number of elements in the array
/// Auxiliary Space   : O(1)
void printSpanNaive(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int span = 1;
        for(int j = i-1; j >= 0 && arr[j] <= arr[i]; j--)
            span++;
        cout << span << " "; 
    }
    cout << endl;
}

/// Efficient Solution
/// Time Complexcity  :O(N), where N is number of elements in the array
/// Auxiliary Space   :O(N), where N is number of elements in the array
void printSpan(int arr[], int n) {
    stack<int> st;
    cout << 1 << " ";
    st.push(0);
    for(int i = 1; i < n; i++) {
        while(!st.empty() && (arr[st.top()] <= arr[i])) st.pop();
        cout << ((st.empty()) ? i+1 : i-st.top()) << " ";
        st.push(i);
    }
}


int main() {

    cout << "-------------------- Naive Solution ----------------------- " << endl;
    cout << "Test Case 1 : " << endl;
    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int size = 10;
    cout << "arr : ";
    print(arr, size);
    cout << "span : ";
    printSpanNaive(arr, size);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    int arr3[] = {10, 20, 30, 40};
    int size3 = 4;
    cout << "arr : ";
    print(arr3, size3);
    cout << "span : ";
    printSpanNaive(arr3, size3);
    cout << endl;

    cout << "-------------------- Efficient Solution ----------------------- " << endl;
    cout << "Test Case 1 : " << endl;
    int arr2[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int size2 = 10;
    cout << "arr : ";
    print(arr2, size2);
    cout << "span : ";
    printSpan(arr2, size2);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    int arr4[] = {10, 20, 30, 40};
    int size4 = 4;
    cout << "arr : ";
    print(arr4, size4);
    cout << "span : ";
    printSpanNaive(arr4, size4);
    cout << endl;


  return 0;
}
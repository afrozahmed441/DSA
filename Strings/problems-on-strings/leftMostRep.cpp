#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*

- Problem   : Give a string, find the left most repeating character index 

- input     : string
- output    : index of left most repeating character

*/

/// ------------------------------- Main Logic ------------------------------------
/// Time Complexcity : O(N), where N is number of characters in string
/// Auxiliary Space  : O(SIZE)
int leftRepInd(const string &s) {
    const int SIZE = 26;
    int arr[SIZE] = {0};
    /// count frequency of characters in string 
    for(int i = 0; i < s.size(); i++) {
        arr[tolower(s[i])-'a']++;
    }
    /// iterate through string from left to right 
    for(int i = 0; i < s.size(); i++) {
        if(arr[tolower(s[i])-'a'] > 1) return i;
    }
 return -1;
}

int main() {

    string s = "abbcc";
    cout << "Test Case 1 : " << endl;
    cout << "string : " << s << endl;
    cout << "res : " << leftRepInd(s) << endl;
    cout << endl;

    string s2 = "abcd";
    cout << "Test Case 2 : " << endl;
    cout << "string : " << s2 << endl;
    cout << "res : " << leftRepInd(s2) << endl;
    cout << endl;

    string s3 = "aabbccdd";
    cout << "Test Case 3 : " << endl;
    cout << "string : " << s3 << endl;
    cout << "res : " << leftRepInd(s3) << endl;
    cout << endl;

 return 0;
}
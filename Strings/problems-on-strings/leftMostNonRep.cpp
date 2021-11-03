#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*

- Problem   : Given a string, find the left most non repeating character

- input     : string
- output    : index of left most non repeating character

*/

/// ------------------------------- Main Logic ------------------------------------
int leftMostNonRep(const string &s) {
    const int SIZE = 26;
    int arr[SIZE] = {0};
    for(int i = 0; i < s.size(); i++) {
        arr[tolower(s[i])-'a']++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(arr[tolower(s[i])-'a'] == 1) return i;
    }
  return -1;   
}

/// another method
int leftMostNonRepV(const string &s) {
    const int SIZE = 26;
    bool vis[SIZE] = {false};
    int res = -1;
    for(int i = s.size()-1; i >= 0; i--) {
        if(vis[tolower(s[i])-'a']) {
            res = -1;
        } else {
            res = i;
            vis[tolower(s[i])-'a'] = true;
        }
    }
    return res;
}

int main() {
    string s = "abbcc";
    cout << "Test Case 1 : " << endl;
    cout << "string : " << s << endl;
    cout << "res : " << leftMostNonRep(s) << endl;
    cout << "res : " << leftMostNonRepV(s) << endl;
    cout << endl;

    string s2 = "abcd";
    cout << "Test Case 2 : " << endl;
    cout << "string : " << s2 << endl;
    cout << "res : " << leftMostNonRep(s2) << endl;
    cout << "res : " << leftMostNonRepV(s2) << endl;
    cout << endl;

    string s3 = "aabbccdd";
    cout << "Test Case 3 : " << endl;
    cout << "string : " << s3 << endl;
    cout << "res : " << leftMostNonRep(s3) << endl;
    cout << "res : " << leftMostNonRepV(s3) << endl;
    cout << endl;
 
 return 0;
}
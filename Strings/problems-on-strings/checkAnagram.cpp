#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*

- Problem   : Given two string check whether given two strings are anagram of each other or not

- input     : Two strings
- output    : true or false

*/

/// ------------------------------- Main Logic ------------------------------------
/// Time Complexcity : O(N), where N is number of characters in a given string
/// Anagrams have following properties 
/// both the strings have same number of characters 
/// both the strings have same characters in string, but may not be in same sequence
bool checkAnagram(const string &s1, const string &s2) {
    /// if lenght of s1 is not equal to s2 then they can't be anagrams
    if(s1.size() != s2.size()) return false;

    const int SIZE = 26;
    int arr[SIZE] = {0};
    /// if lengths are same then check characters in the strings
    for(int i = 0; i < s1.size(); i++) {
        arr[tolower(s1[i])-'a']++;
        arr[tolower(s2[i])-'a']--;
    }
    /// check if there is a character that is not present in one of them.
    for(int i = 0; i < SIZE; i++) {
        if(arr[i] != 0) return false;
    }

  return true;
}

int main() {

    string s1 = "listen";
    string s2 = "silent";
    cout << "Test Case 1 : " << endl;
    cout << "res : " << checkAnagram(s1, s2);
    cout << endl;

    string s3 = "aaacb";
    string s4 = "cabaa";
    cout << "Test Case 2 : " << endl;
    cout << "res : " << checkAnagram(s3, s4);
    cout << endl;

    string s5 = "aab";
    string s6 = "abb";
    cout << "Test Case 3 : " << endl;
    cout << "res : " << checkAnagram(s5, s6);
    cout << endl;

 return 0;
}
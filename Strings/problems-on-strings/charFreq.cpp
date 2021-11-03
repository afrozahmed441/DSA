#include <iostream>
#include <string>
using namespace std;

/*

- Problem   : Given a string find the frequency of characters in the string 

- input     : string
- output    : frequency of characters in string

*/

/// ----------------------- Main Logic --------------------------------------------
void charFreq(string &s) {
    int arr[26] = {0};
    /// count char frequency
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }
    /// print char frequency 
    for(int i = 0; i < 26; i++) {
        if(arr[i]>0) cout <<  (char)(i+'a') << " : " << arr[i] << endl;
    }
}

int main() {

    string name = "afroz ahmed shaik";
    cout << "Test Case 1 : " << endl;
    charFreq(name);
    cout << endl;
    
 return 0;
}
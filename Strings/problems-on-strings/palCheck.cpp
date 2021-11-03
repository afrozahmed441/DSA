#include <iostream>
#include <cctype>
using namespace std;

/*

- Problem   : Given a string, check it is a palindrone or not

- input     : string
- output    : true or false

*/

/// --------------------------- Main Logic ----------------------------------------
bool checkPalin(const string &s) {
    int st = 0;
    int en = s.size() - 1;
    while(st < en) {
        if(tolower(s[st]) != tolower(s[en])) return false;
        st++;
        en--;
    }
    return true;
}

int main() {

    string s = "Aka";
    cout << "Test Case 1 : " << endl;
    cout << "res : " << checkPalin(s);
    cout << endl;

    string s2 = "Affa";
    cout << "Test Case 2 : " << endl;
    cout << "res : " << checkPalin(s2);
    cout << endl;

    string s3 = "hieeih";
    cout << "Test Case 3 : " << endl;
    cout << "res : " << checkPalin(s3);
    cout << endl;

    string s4 = "afroz";
    cout << "Test Case 4 : " << endl;
    cout << "res : " << checkPalin(s4);
    cout << endl;

 return 0;
}
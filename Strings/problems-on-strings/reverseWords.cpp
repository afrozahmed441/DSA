#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*

- Problem   : Given a string reverse the words in the given string

- input     : string
- output    : reverse words in the string

*/

/// ---------------------------- Main Logic ----------------------------------------
void reverseWordsI(string &s) {
    string word = "";
    stack<string> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') word += s[i];
        else {
            st.push(word);
            word = "";
        }
    }
    st.push(word);

    s = "";
    
    while(!st.empty()) {
        string str = st.top();
        s = s + str + " ";
        st.pop(); 
    }
}

/// recersive method 
void reverse(string &s, int st, int en) {
    while(st < en) {
        swap(s[st], s[en]);
        st++;
        en--;
    }
}

void reverseWords(string &s) {
    int en = 0, st = 0;
    while(en < s.size()) {
        if(s[en] != ' ') en++;
        else {
            reverse(s, st, en);
            st = en+1;
            en++;
        }
    }
    reverse(s, st, s.size()-1);
    reverse(s, 0, s.size()-1);
}

int main() {

    cout << "----------------- Iterative Method ------------------------" << endl;
    string s = "I love coding";
    cout << "str  : " << s << endl;
    reverseWordsI(s);
    cout << "res : " << s << endl;
    cout << endl;

    cout << "----------------- Recersive Method ------------------------" << endl;
    cout << "str  : " << s << endl;
    reverseWords(s);
    cout << "res : " << s << endl;
    cout << endl;

 return 0;
}
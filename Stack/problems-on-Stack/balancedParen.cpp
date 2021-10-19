#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   : Given a set of parenthesis check whethere they are balanced or not

- input     : string ( possible characters '(' ')' '{' '}' '[' ']'
- output    : true or false

- Example Test Cases:
  i/o : {[()]}
  o/p : true

  i/o : {({})}
  o/p : true

  i/o : {[(])}
  o/p : false

*/

//// ---------------------------------- Main Logic --------------------------------
/// checkTop function (compare the top of stack with current char)
bool checkTop(char a, char b) {
    if(a == '(' && b == ')') return true;
    else if(a == '{' && b == '}') return true;
    else if(a == '[' && b == ']') return true;
    return false;
}

/// balanced Paren Function
bool balancedParen(const string &in) {

    stack<char> st;
    for(const char &c : in) {

        if(c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if(st.empty()) return false;
            else if(checkTop(st.top(), c) == false) return false;
            else st.pop();
        }

    }
    return (st.empty() == true);
}

int main() {

    cout << "Test Case 1 : "<< endl;
    string input = "([])";
    cout << "[INPUT] : " << input << endl;
    cout << "[RESULT] : " << balancedParen(input) << endl;
    cout << endl;

    cout << "Test Case 2 : "<< endl;
    string input2 = "([{}])";
    cout << "[INPUT] : " << input2 << endl;
    cout << "[RESULT] : " << balancedParen(input2) << endl;
    cout << endl;

    cout << "Test Case 3 : "<< endl;
    string input3 = "([{]})";
    cout << "[INPUT] : " << input3 << endl;
    cout << "[RESULT] : " << balancedParen(input3) << endl;
    cout << endl;

    cout << "Test Case 4 : "<< endl;
    string input4 = "((())";
    cout << "[INPUT] : " << input4 << endl;
    cout << "[RESULT] : " << balancedParen(input4) << endl;
    cout << endl;

  return 0;
}
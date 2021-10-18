#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   : given infix expression convert it into postfix expression

- input : infix expression
- ouput : postfix expression

- Example Test Cases
  i/o : a+b
  o/p : ab+

  i/o : a+b*c
  o/p : abc*+

  i/o : a+b*(c-d)
  o/p : abcd-*+

*/

//// ----------------------- Main Logic --------------------------------------
void infixToPostfix(const string &s) {

    int i = 0;
    stack<char> st;
    while(i < s.size()) {

        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) cout << s[i];

        else if(s[i] == '(') st.push(s[i]); 

        else if(s[i] == ')') {
            while(st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }

        else if(s[i] == '+' || s[i] == '-') {
            while(!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }

        else if(s[i] == '*' || s[i] == '/') {
            while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }

        i++;

    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {

    cout << "Test Case 1 : " << endl;
    string infix = "a+b*c";
    cout << "[INFIX EXP] : " << infix << endl;
    cout << "[POSTFIX EXP] : ";
    infixToPostfix(infix);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    string infix2 = "a+b*c/d";
    cout << "[INFIX EXP] : " << infix2 << endl;
    cout << "[POSTFIX EXP] : ";
    infixToPostfix(infix2);
    cout << endl;
 
    cout << "Test Case 3 : " << endl;
    string infix3 = "a+b*c/d+e";
    cout << "[INFIX EXP] : " << infix3 << endl;
    cout << "[POSTFIX EXP] : ";
    infixToPostfix(infix3);
    cout << endl;

    cout << "Test Case 4 : " << endl;
    string infix4 = "a+b*c/d+e+f";
    cout << "[INFIX EXP] : " << infix4 << endl;
    cout << "[POSTFIX EXP] : ";
    infixToPostfix(infix4);
    cout << endl;

 return 0;
}
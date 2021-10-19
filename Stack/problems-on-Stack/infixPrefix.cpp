#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

/*

- Problem   : Given infix expression convert it into prefix expression

- input     : infix expression
- output    : prefix expression

- Example Test Cases:
  i/o : a+b
  o/P : +ab

  i/o : a+b*c
  i/p : +a*bc

NOTE : input the expression without any spaces in between.
NOTE : operators are + - * / only.
*/

///// ------------------------------- Main Logic ---------------------------------
/**
 * Algo:
 * Create a empty stack (st)
 * Create a string variable (res)
 * Travel the infix expression from the right to left.
 * if the current character is operand then append the character to the res.
 * if the current character is '(' then push the char into the stack
 * if the current character is ')' then pop the stack until we find '(' and pop the stack top one last time to remove '('
 * if the current character is operator
 * if the operator has higher precedence than stack top then push that into the stack.
 * if the operator has lower precedence than stack top then pop stack and append the pop elements to res, pop until we find a higher precedence operator or until stack is empty
 * if the operator has equal precedence then use associativity 
 * if stack is not empty then pop the elements and append to res.
 * reverse the res and return the prefix.
*/
void infixTOPrefix(const string &in) {
    int i = in.size() - 1;
    stack<char> st;
    string res = "";
    while(i >= 0) {
        /// if operand
        if((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z')) res += in[i];

        else if(in[i] == ')') st.push(in[i]);

        else if(in[i] == '(') {
            while(!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }

        /// if operator 
        else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/') {

            if(in[i] == '+' || in[i] == '-') {
                while(!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')) {
                    res += st.top();
                    st.pop();
                }
            }

            else if(in[i] == '*' || in[i] == '/') {
                while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    res += st.top();
                    st.pop();
                }
            }

            st.push(in[i]);

        }

        --i;

    }
     /// check if the stack has any elements 
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }

    /// reverse the res
    reverse(res.begin(), res.end());

    cout << res << endl;
}

int main() {

    cout << "Test Case 1 : " << endl;
    string infix1 = "a+b";
    cout << "[INFIX EXP] : " << infix1 << endl;
    cout << "[PREFIX EXP] : ";
    infixTOPrefix(infix1);
    cout << endl;

    cout << "Test Case 2 : " << endl;
    string infix2 = "a+b*c";
    cout << "[INFIX EXP] : " << infix2 << endl;
    cout << "[PREFIX EXP] : ";
    infixTOPrefix(infix2);
    cout << endl;

    cout << "Test Case 3 : " << endl;
    string infix3 = "(a+b)*c";
    cout << "[INFIX EXP] : " << infix3 << endl;
    cout << "[PREFIX EXP] : ";
    infixTOPrefix(infix3);
    cout << endl;

    cout << "Test Case 4 : " << endl;
    string infix4 = "(a+b)*(c+d)";
    cout << "[INFIX EXP] : " << infix4 << endl;
    cout << "[PREFIX EXP] : ";
    infixTOPrefix(infix4);
    cout << endl;

    return 0;
}
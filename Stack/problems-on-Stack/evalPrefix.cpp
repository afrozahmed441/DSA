#include <iostream>
#include <stack>
using namespace std;

/*

- Problem   :  Given a Prefix expression, evaluate the prefix expression and print the result

- input     : prefix expression (with no spaces and only single digits)
- output    : result of prefix expression

- Example Test Cases:
  i/o : +12
  o/p : 3

  i/o : *+123
  o/p : 9

*/

///// --------------------------------------- Main Logic ---------------------------
/// eval function 
int eval(int a, int b, char op) {
    switch (op)
    {
    case '+':
        return (a+b);
    case '-':
        return (a-b);
    case '*':
        return (a*b);
    case '/':
        return (a/b);
    }
    return 0;
}


/**
 * Algo:
 * Create a empty Stack (st)
 * Travel the given prefix expression from right to left
 * if the current character is operand push the operand into the stack
 * if the current character is operator then pop the first two operands and perform the operation and push back the result into the stack
 * After we complete traversing the prefix expression, return the top of the stack
 * top of the stack is result of the prefix expression.
*/
int evalPrefix(const string &in) {

    int i = in.size()-1;
    stack<int> st;
    while(i >= 0) {

        if(in[i] >= '0' && in[i] <= '9') st.push((int)in[i] - '0');
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(eval(a, b, in[i]));
        }

        --i;

    }
  return st.top();
}


/// main function
int main() {

    cout << "Test Case 1: " << endl;
    string prefix = "+12";
    cout << "[PREFIX] : " << prefix << endl;
    cout << "[RESULT] : " << evalPrefix(prefix) << endl;
    cout << endl;

    cout << "Test Case 2: " << endl;
    string prefix2 = "+9*26";
    cout << "[PREFIX] : " << prefix2 << endl;
    cout << "[RESULT] : " << evalPrefix(prefix2) << endl;
    cout << endl;

    cout << "Test Case 3: " << endl;
    string prefix3 = "*+123";
    cout << "[PREFIX] : " << prefix3 << endl;
    cout << "[RESULT] : " << evalPrefix(prefix3) << endl;
    cout << endl;

    cout << "Test Case 4: " << endl;
    string prefix4 = "-+8/632";
    cout << "[PREFIX] : " << prefix4 << endl;
    cout << "[RESULT] : " << evalPrefix(prefix4) << endl;
    cout << endl;


 return 0;
}
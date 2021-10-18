#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

/*

- Problem   : given Postfix expression, evaluate the given postfix expression 

- input     : Postfix expression
- output    : result of the postfix expression

- Example Test Cases
  i/o : 12+
  o/p : 3

  i/o : 23+3*
  o/p : 15

  i/o : 12+3*
  o/p : 9

- NOTE : operators are +, -, *, /
*/

//// ----------------------------- Main Logic ----------------------------------
int eval(int a, int b, char op) {
    switch (op) {
    case '+':
        return (b+a);
    case '-':
        return (b-a);
    case '*':
        return (b*a);
    case '/':
        return (b/a);
    default:
        break;
    }
    return 0;
}

/// eval with string op
int eval(int a, int b, string op) {
    int res = 0;
    if(op == "+") res = b + a;
    else if(op == "-") res = b - a;
    else if(op == "*") res = b * a;
    else if(op == "/") res = b/a;
    return res;
}

int evalPostfix(string in) {
    /// Algo : 
    /**
     * Create a empty Stack 
     * Travel through the given postfix expression
     * if the current char is operand then push it ino the stack
     * else, if it is a operator then pop top two items and perform the operation
     * push the result into the stack 
    */

   stack<int> st;
   int i = 0;

   while(in[i] != '\0') {

       if(isdigit(in[i])) {
           int d = (int)in[i] - '0';
           st.push(d);
       }
       else {
           int a = st.top();
           st.pop();
           int b = st.top();
           st.pop();
           int res = eval(a, b, in[i]);
           st.push(res);
       }
      i++;
   }
  return st.top();
}

/// check given string is num or not
bool isNum(const string &s) {
    for(const char &c : s) {
        if(!isdigit(c)) return false;
    }
    return true;
}
 
//// split function
void sep(string &s, vector<string> &in) {
    int i = 0;
    string t = "";    
    while(i < s.size()) {
        
        if(s[i] != ' '){
            t += s[i];
        }

        else {
            in.push_back(t);
            t = "";
        }

        i++;
    }
    in.push_back(t);
}

int evalPostfixM(string in) {
    stack<int> st;
    vector<string> sv;
    sep(in, sv);
    int i = 0;
    while(i < sv.size()) {
        
        if(isNum(sv[i])) st.push(stoi(sv[i]));
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(eval(a, b, sv[i]));
        }
        i++;

    }
    return st.top();
}

int main() {
    
    cout << "Test Case 1 : " << endl; 
    string exp = "12+3*";
    int res = evalPostfix(exp);
    cout << "[POSTFIX EXP] : " << exp << endl;
    cout << "[RESULT] : " << res << endl;
    cout << endl;

    cout << "Test Case 2 : " << endl; 
    string exp2 = "12*35*+9-";
    int res2 = evalPostfix(exp2);
    cout << "[POSTFIX EXP] : " << exp2 << endl;
    cout << "[RESULT] : " << res2 << endl;
    cout << endl;

    cout << "----------------------- Multiple Digits --------------------------" << endl;
    string exp3 = "10 2 * 3 5 * + 9 -";
    int res3 = evalPostfixM(exp3);
    cout << "[POSTFIX EXP] : " << exp3 << endl;
    cout << "[RESULT] : " << res3 << endl;
    cout << endl;

 return 0;
}
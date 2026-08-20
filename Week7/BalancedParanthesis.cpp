#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balancedParentheses(string expression) {
    stack<char> st;

    for (char ch : expression) {

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string expression;

    cin >> expression;

    bool result = balancedParentheses(expression);

    cout << boolalpha << result;

    return 0;
}

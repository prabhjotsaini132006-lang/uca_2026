#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evalPostfix(string s) {
    stack<int> result;
    string token = "";

    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {

            if (token == "")
                continue;

            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = result.top();
                result.pop();

                int a = result.top();
                result.pop();

                int res;

                if (token == "+")
                    res = a + b;
                else if (token == "-")
                    res = a - b;
                else if (token == "*")
                    res = a * b;
                else
                    res = a / b;

                result.push(res);
            }
            else {
                result.push(stoi(token));
            }

            token = "";
        }
        else {
            token += s[i];
        }
    }

    return result.top();
}

int main() {
    string s;

    cout << "Enter the expression: ";
    getline(cin, s);

    int result = evalPostfix(s);

    cout << result << endl;

    return 0;
}

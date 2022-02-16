#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
#include <sstream>

using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        stack<int> _stack;
        vector<string> str;
        if (input == ".") break;
        string tmp = "";
        for (size_t i = 0;i <= input.size();i++) {
            if (input[i] == ' ' || input[i] == '\0') {
                str.push_back(tmp);
                tmp = "";
            }
            else {
                tmp += input[i];
            }
        }
        bool legal = true;
        for (int i = str.size() - 1;i >= 0;i--) {
            int x = -1;
            std::string::iterator z = str[i].begin();
            while (z != str[i].end() && std::isdigit(*z))z++;
            bool is_digit = (z == str[i].end());

            if (is_digit) {
                stringstream degree(str[i]);
                degree >> x;
                _stack.push(x);
            }
            else {
                if (_stack.empty()) {
                    legal = false;
                    break;
                }
                int a = _stack.top();
                // cout << "pop the " << a << "\n";
                _stack.pop();
                if (_stack.empty()) {
                    legal = false;
                    break;
                }
                int b = _stack.top();
                // cout << "pop the " << b << "\n";
                _stack.pop();
                int res = -1;
                if (str[i] == "+") {
                    res = a + b;
                }
                else if (str[i] == "-") {
                    res = a - b;
                }
                else if (str[i] == "*") {
                    res = a * b;
                }
                else if (str[i] == "/") {
                    res = a / b;
                }
                else if (str[i] == "%") {
                    res = a % b;
                }
                // cout << "push the " << res << "\n";
                _stack.push(res);
            }

        }
        if (legal) {
            cout << _stack.top() << endl;
        }
        else {
            cout << "illegal\n";
        }
    }
    return 0;
}
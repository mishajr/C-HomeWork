#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areParenthesesBalanced(const string& expression) {
    stack<char> stack;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    string expression;
    cout << "Enter a string with parentheses: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "The string contains correctly positioned parentheses." << endl;
    } else {
        cout << "The string contains incorrectly positioned parentheses." << endl;
    }


}

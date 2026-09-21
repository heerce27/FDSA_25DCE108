#include <iostream>
#include <string>
using namespace std;
class Stack {
    char arr[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(char x) {
        top++;
        arr[top] = x;
    }
    char pop() {
        char x = arr[top];
        top--;
        return x;
    }
    char peek() {
        return arr[top];
    }
    bool empty() {
        return top == -1;
    }
};

int priority(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";
    for (char ch : infix) {
        // If operand
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If opening bracket
        else if (ch == '(') {
            st.push(ch);
        }
        // If closing bracket
        else if (ch == ')') {
            while (!st.empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            // Remove '('
            if (!st.empty()) {
                st.pop();
            }
        }
        // If operator
        else if (isOperator(ch)) {
            while (!st.empty() && st.peek() != '(' && priority(st.peek()) >= priority(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }
    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    cout << "Postfix expression: "<< infixToPostfix(infix);
    return 0;
}
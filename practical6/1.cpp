#include <iostream>
using namespace std;
class MyStack {
    int *stack;
    int top;
    int capacity;
public:
    MyStack(int n) {
        capacity = n;
        stack = new int[capacity];
        top = -1;
    }
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Error: Stack Overflow - Cannot place tray "
                 << x << endl;
            return;
        }
        top++;
        stack[top] = x;
        cout << "Placed tray: " << x << endl;
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Current top tray: " << stack[top] << endl;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Error: Stack Underflow - Cannot take tray" << endl;
            return;
        }
        cout << "Taken tray: " << stack[top] << endl;
        top--;
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Current top tray: " << stack[top] << endl;
        }
    }
    ~MyStack() {
        delete[] stack;
    }
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;
    MyStack st(n);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}
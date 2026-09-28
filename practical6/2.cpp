#include <iostream>
using namespace std;
class Node {
public:
    string page;
    Node* next;
    Node(string p) {
        page = p;
        next = NULL;
    }
};
class BrowserHistory {
    Node* top;
public:
    BrowserHistory() {
        top = NULL;
    }
    void visit(string page) {
        Node* temp = new Node(page);
        temp->next = top;
        top = temp;
        cout << "Visited: " << page << endl;
        cout << "Current page: " << top->page << endl;
    }
    void back() {
        if (top == NULL) {
            cout << "Error: No history available. Cannot go back."
                 << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        if (top == NULL) {
            cout << "Current page: No page" << endl;
        } else {
            cout << "Current page: " << top->page << endl;
        }
    }
    ~BrowserHistory() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main() {
    BrowserHistory browser;
    browser.visit("Google");
    browser.visit("YouTube");
    browser.visit("GitHub");
    browser.visit("Coursera");
    cout<<"\nBack operations:\n";
    browser.back();
    browser.back();
    browser.back();
    browser.back();
    return 0;
}
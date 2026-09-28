#include <iostream>
using namespace std;

class TokenQueue {
    int *queue;
    int n;
    int front, rear, count;

public:
    TokenQueue(int size) {
        n = size;
        queue = new int[n];
        front = 0;
        rear = 0;
        count = 0;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty\n";
            cout << "Front: -\n";
            cout << "Rear: " << rear << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = 0; i < count; i++) {
            int index = (front + i) % n;
            cout << queue[index] << " ";
        }
        cout << endl;
}

    void join(int token) {
        if (count == n) {
            cout << "Error: Queue is full\n";
            return;
        }

        queue[rear] = token;
        rear = (rear + 1) % n;
        count++;

        cout << "\nAfter Join:\n";
        display();
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty\n";
            return;
        }

        cout << "Served token: " << queue[front] << endl;

        front = (front + 1) % n;
        count--;

        cout << "\nAfter Serve:\n";
        display();
    }
};

int main() {
    int n, operations;

    cout << "Enter queue capacity: ";
    cin >> n;

    TokenQueue q(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        char operation;

        cout << "\nEnter operation (J/j for Join, S/s for Serve): ";
        cin >> operation;

        if (operation == 'J' || operation == 'j') {
            int token;

            cout << "Enter token number: ";
            cin >> token;

            q.join(token);
        }
        else if (operation == 'S' || operation == 's') {
            q.serve();
        }
        else {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}
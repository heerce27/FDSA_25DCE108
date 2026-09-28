#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;
    Node(int p) {
        patient = p;
        next = nullptr;
    }
};

class PatientQueue {
    Node* front;
    Node* rear;
public:
    PatientQueue() {
        front = nullptr;
        rear = nullptr;
    }
    void arrive(int patient) {
        Node* newNode = new Node(patient);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Queue: ";
        display();
        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: No patients waiting\n";
            return;
        }
        cout << "Attended patient: " << front->patient << endl;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
            cout << "Queue is empty\n";
        } else {
            cout << "Queue: ";
            display();
            cout << "Front patient: " << front->patient << endl;
        }
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->patient << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PatientQueue q;
    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;
    for (int i = 0; i < operations; i++) {
        char operation;
        cout << "\nEnter operation (A/a for Arrive, T/t for Attend): ";
        cin >> operation;
        if (operation == 'A' || operation == 'a') {
            int patient;
            cout << "Enter patient number: ";
            cin >> patient;
            q.arrive(patient);
        }
        else if (operation == 'T' || operation == 't') {
            q.attend();
        }
        else {
            cout << "Invalid operation\n";
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int table[10];
    for (int i = 0; i < 10; i++) {
        table[i] = -1;
    }
    int n, id;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;
        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int index;
        int j;
        for (j = 0; j < 10; j++) {
            index = (h1 + j * h2) % 10;
            if (table[index] == -1) {
                table[index] = id;
                cout << "Student " << id << " placed at slot "<< index << endl;
                break;
            }
        }
        if (j == 10) {
            cout << "Cannot insert student "<< id << ". No reachable empty slot.\n";
        }
    }
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }
    return 0;
}
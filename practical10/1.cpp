#include <iostream>
using namespace std;
int main() {
    int slots[10];
    for (int i = 0; i < 10; i++) {
        slots[i] = -1;
    }
    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int reg;
        cout << "Enter registration number: ";
        cin >> reg;
        int index = reg % 10;
        int start = index;
        while (slots[index] != -1) {
            index = (index + 1) % 10;
            if (index == start) {
                cout << "Parking lot is full! Vehicle " << reg << " cannot be parked.\n";
                break;
            }
        }
        if (slots[index] == -1) {
            slots[index] = reg;
            cout << "Vehicle " << reg << " parked in slot " << index << endl;
        }
    }
    cout << "\nFinal Parking Lot State:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (slots[i] == -1)
            cout << "Empty";
        else
            cout << slots[i];
        cout << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count0 = 0, count1 = 0, count2 = 0;
   
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }
    
    int index = 0;
    while (count0--)
        arr[index++] = 0;

    while (count1--)
        arr[index++] = 1;

    while (count2--)
        arr[index++] = 2;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
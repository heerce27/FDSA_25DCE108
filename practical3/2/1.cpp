#include <iostream>
using namespace std;
int main() {
    int arr[] = {2, 0, 1, 2, 1, 0,2,1,0,0,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);;
    int pos = 0;
    cout<<"Before Sorting:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    
    for (int i = pos; i < n; i++) {
        if (arr[i] == 1) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    cout<<"\nAfter Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
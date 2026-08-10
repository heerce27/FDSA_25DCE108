#include <iostream>
using namespace std;
int main()
{
    int n, h;
    cout << "Enter number of items: ";
    cin >> n;
    int arr[n], temp[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number of hours: ";
    cin >> h;
    h=h%n;
    for(int i = 0; i < n; i++)
    {
        temp[i]=arr[(i + h) % n];
    }
    cout << "Final array after rotation:\n";
    for(int i = 0; i < n; i++)
    {
        cout <<temp[i]<< " ";
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;
    int arr[n];
    cout << "Enter book IDs: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Book IDs borrowed more than once:\n";
    for(int i = 0; i < n; i++)
    {
        int count = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count > 1)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}

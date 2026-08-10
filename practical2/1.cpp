#include<iostream>
using namespace std;
int recursiveSearch(string arr[], int n, string s, int index)
{
    if (index >= n)
    {
        return -1; 
    }
    if (arr[index] == s)
    {
        return index; 
    }
    return recursiveSearch(arr, n, s, index + 1); 
}
int main()
{
    cout<<"Enter no of vehicles : ";
    int n;
    cin>>n;
    string arr[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Enter licanse plate number : ";
        cin>>arr[i];
    }
    cout<<"Enter licanse plate number to search : ";
    string s;
    cin>>s;
    int f=0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==s)
        {
            cout<<"Vehicle found at index : "<<i+1;
            f=1;
            break;
        }
    }
    if (f==0)
    {
        cout<<"Vehicle not found";
    }
    cout<<"\nUsing recursive search : ";
    int index = recursiveSearch(arr, n, s, 0);
    if (index != -1)
    {
        cout<<"Vehicle found at index : "<<index+1;
    }
    else
    {
        cout<<"Vehicle not found";
    }
    return 0;
}

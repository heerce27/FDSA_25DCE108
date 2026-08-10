#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter no of students:";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int f;
    cout<<"Enter k:";
    cin>>f;
    int start=0,end=n-1,fn=0;
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==f)
        {
            cout<<"Roll no. found at index : "<<mid+1;
            fn=1;
            break;
        }
        else if(a[mid]<f)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    } 
    if(fn==0)
    {
        cout<<"Roll no. not found";
    }
}
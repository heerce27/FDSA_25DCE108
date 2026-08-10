#include<iostream>
using namespace std;
int recursiveSearch(int arr[], int start, int end, int target)
{
    if(start>end)
    return 0;
    int mid=(start+end)/2;
    if(arr[mid]==target)
    return mid;
    else if(arr[mid]<target)
    {
        return recursiveSearch(arr,mid+1,end,target);
    }
    else{
        return recursiveSearch(arr,start,mid-1,target);
    }
}
int main()
{
    cout<<"Enter no of codes:";
    int n;
    cin>>n;
    int arr[n];
    int s=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=s++;
    }
    int f;
    cout<<"Enter code to search : ";
    cin>>f;
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==f)
        {
            cout<<"\nCode found at index : "<<mid+1;
            break;
        }
        else if(arr[mid]<f)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }

    int r=recursiveSearch(arr,0,n-1,f);
    if(r!=0)
    cout<<"\nCode found at "<<r+1<<" position";
    else
    cout<<"Code not found";  
}
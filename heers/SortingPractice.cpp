#include<iostream>
using namespace std;
void insertionsort(int a[],int n){
    for(int i=0;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int getM(int a[],int n){
    int mx=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    return mx;
}
void CountingS(int a[],int n){
    int count[10]= { 0 };
    int output[n];
    int max=getM(a,n);
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=0;i<n;i++){
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    for(int i=0; i<n; i++){
    a[i] = output[i];
}
}

int main(){
    int a[5]={8,5,6,8,3};
    for(int i=0;i<5;i++){
        cout<<" "<<a[i];
    }
    //insertionsort(a,5);
    CountingS(a,5);
    for(int i=0;i<5;i++){
        cout<<" "<<a[i];
    }
}
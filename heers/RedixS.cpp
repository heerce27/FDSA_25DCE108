#include<iostream>
using namespace std;

int getM(int a[],int n){
    int mx=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    return mx;
}
void CountingS(int a[],int n,int exp){
    int count[10]= { 0 };
    int output[n];
    int max=getM(a,n);
    for(int i=0;i<n;i++){
        int digit=(a[i]/exp)%10;
        count[digit]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int digit=(a[i]/exp)%10;
        output[count[digit]-1]=a[i];
        count[digit]--;
    }
    for(int i=0; i<n; i++){
    a[i] = output[i];
}
}

void RedixS(int a[],int n)
{
    int max=getM(a,n);
    for(int exp=1; max/exp>0 ; exp*=10 )
    {
        CountingS(a,n,exp);
    }
}
int main(){
    int a[5]={8,5,6,8,3};
    for(int i=0;i<5;i++){
        cout<<" "<<a[i];
    }
    cout<<"\n";
    RedixS(a,5);
    for(int i=0;i<5;i++){
        cout<<" "<<a[i];
    }
}

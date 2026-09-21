#include<iostream>
using namespace std;

int linearSearch(int a[], int n, int key, int &compare)
{
    compare = 0;
    for (int i = 0; i < n; i++)
    {
        compare++;
        if (a[i] == key)
            return i;
    }
    return -1;
}
int binarySearch(int a[],int n,int key,int &comapare)
{
    int start=0;
    int end=n-1;
    
    while(end<=start)
    {
        comapare++;
        
        int mid= (start+end)/2;
        if(a[mid]==key)
        return mid;
        if(a[mid]<key)
        {
            comapare++;
            end=mid+1;
        }
        else
        {
            comapare++;
            start=mid-1;
        }
        } return -1;
}

void bubbleS(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int CF(int a[],int n, int k){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==k){
            c++;
        }
    }
    return c;
}

bool Report(int a[],int n,int k){
    for(int i=0;i<n;i++){
        if(a[i]==k)
        return true;
    }
    return false;
}

int main(){
    cout<<"Enter no of Badge IDs:";
    int n;
    cin>>n;
    int *a= new int[n];
    int *sort=new int[n];
    int *rep=new int[n];
    cout<<"Enter IDs:";
    int id;
    for(int i=0;i<n;i++){
        cin>>id;
        a[i]=id;
        sort[i]=a[i];
    }
    int repC=0;
    cout<<"Repeated IDs:\n";
    bool rid=false;
    for(int i=0;i<n;i++){
        if(Report(a,n,a[i])){
            continue;
        }
        int f=CF(a,n,a[i]);
        if(f>1){
            cout<<"--------\nBadge ID: "<<a[i];
            cout<<"\nFrequency: "<<f<<endl;
            rep[repC]=a[i];
            repC++;
            rid=true;
        }
    }

    if(!rid){
        cout<<"\nNot repeated\n";
    }

    bubbleS(sort,n);
    cout<<"Sorted ids:\n";
    for(int i=0;i<n;i++){
        cout<<" "<<sort[i];
    }

    cout<<"\nEnter no of queries:";
    int noq;
    cin>>noq;
    if(noq<=0)
 {   cout<<"No query\n";
    delete[] a;
    delete[] sort;
    delete[] rep;
return 0;
 }

 int tlc=0;
 int tbc=0;
 for(int i=0;i<noq;i++){
    int key;
    int lc=0;
    int bc=0;
    cout<<"Id to verify: ";
    cin>>key;
    int op=linearSearch(a,n,key,lc);

    int sc=binarySearch(sort,n,key,bc);
    tlc+=lc;
    tbc+=bc;
    cout<<"\nID:\n";
    if(op!=-1){
        cout<<"Found!\n";
        cout<<"First position in og record: "<<op+1<<endl;
    }
    else
    {
        cout<<"Not found\n";
    }
    cout<<"No of comparisions: \n1: LinearSearch: "<<lc;
    cout<<"\n2: BinearSearch: "<<bc<<endl;

 }

 cout<<"Total comparisions:\n";
 cout<<"Linear Search :"<<tlc<<"\nBinary Search: "<<tbc<<endl;
 if(tlc<tbc)
 cout<<"Linear s is better\n";
 else if(tbc<tlc){
    cout<<"Binary s is better \n";
 }
 else
 cout<<"Both are good";
 delete[] a;
 delete[] sort;
 delete[] rep;
 return 0;

}

#include<iostream>
using namespace std;
void TowerOfH(int n,int source,int aux,int dest)
{
    if(n==1){
    cout<<"Move disk 1 from "<<source<<" to "<<dest<<endl;
    return;
    }
    TowerOfH(n-1,source,dest,aux);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<endl;
    TowerOfH(n-1,aux,source,dest);
}
int main(){
    TowerOfH(3,1,2,3);
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,maxw,word="";
    cout<<"Enter sentance:";
    getline(cin,str);
    for(int i=0;i<=str.length();i++)
    {
        if(i==str.length() || str[i]==' ')
        {
            if(word.length()>maxw.length())
            {
                maxw=word;
            }word="";
        }else{
            word+=str[i];
        }
    }
    cout<<"Longest word:"<<maxw;
    cout<<"\nLength of longest word:"<<maxw.length();
}
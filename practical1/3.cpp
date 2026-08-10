#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,maxw,word="";
    //int len=0,longest=0,endindex=0;
    cout<<"Enter sentance:";
    getline(cin,str);
    /*
    string arr[]=str;
    for(int i=0;i!=str.length();i++)
    {
        if(str[i]==' ')
        {
          if(len>longest)
          {
              longest=len;
          }
        }
        else
        {
            len++;
        }
    }
    */
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
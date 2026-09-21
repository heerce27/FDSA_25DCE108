#include<iostream>
#include<string>
using namespace std;
struct Node
{
    /* data */
    int id;
    Node *next;
Node *prev;
int prio;

};
class TS{
    Node *head;
    Node *tail;
    Node *cur;
    int tm;
    public:
    TS(){
        head=NULL;
        tail==NULL;
        cur==NULL;
        tm=0;
    }
    Node *findT(int id){
        Node *temp=head;
        while(temp!=NULl){
             if (temp->id == id)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    void newt(int id,int pr)
{
    int m=0;
    if(findT!=NULL){
        cout<<"Invalid id, already exists.\n";
        return;
    }
    else if()

}
}
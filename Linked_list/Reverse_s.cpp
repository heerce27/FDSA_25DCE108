#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void insert_at_end(Node **head,int val){
    Node *newn=new Node();
    newn->data=val;
    newn->next=NULL;
   
    if(*head==NULL){
       // newn->pre=NULL;
        *head=newn;
        return;
    }

    Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;
    // newn->pre=temp;
}
void Reverse(Node **head)
{
    Node *pree=NULL;
    Node *cur=*head;
    while(cur!=NULL)
    {
        Node *nextt=cur->next;
        cur->next=pree;
        pree=cur;
        cur=nextt;
    }
}

void display(Node *head){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    Node *temp=head;
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
    }
}

int main(){
    Node *head=NULL;
    insert_at_end(&head, 30);
    insert_at_end(&head,60);
    insert_at_end(&head,90);
    display(head);
    Reverse(&head);
    display(head);
}
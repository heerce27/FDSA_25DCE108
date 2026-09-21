#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *pre;
};
void insert_at_begining(Node **head, int val){
    Node *newn=new Node();
    newn->data=val;
    newn->next=*head;
    newn->pre=NULL;
    if(*head!=NULL){
        (*head)->pre=newn;
    }
    *head=newn;
}

void insert_at_end(Node **head,int val){
    Node *newn=new Node();
    newn->data=val;
    newn->next=NULL;
   
    if(*head==NULL){
        newn->pre=NULL;
        *head=newn;
        return;
    }

    Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;
     newn->pre=temp;
}

void insert_at_pos(Node **head,int song,int val){
    Node *temp=*head;
    while(temp!=NULL && temp->data!=song){
        temp=temp->next;
    } 
    if(temp==NULL){
        cout<<"Song not found\n";
        return;
    }          
    Node* newn=new Node();
    newn->data=val;
    newn->next=temp->next;
    newn->pre=temp;
    if (temp->next != NULL)
    {
        temp->next->pre = newn;
    }
    temp->next = newn;                                                                                                    
}

void display(Node *head){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    int c=0;
    Node *temp=head;
    while(temp != NULL){
        cout<<" "<<temp->data;
        c++;
        temp=temp->next;
    }
    cout<<"\nSong count : "<<c<<endl;
}

void delete_first(Node **head){
    if (*head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->pre = NULL;
    }
    delete temp;
}

int main()
{
    Node *head = NULL;
    insert_at_begining(&head, 10);
    display(head);

    insert_at_end(&head, 20);
    display(head);

    insert_at_end(&head, 30);
    display(head);

    insert_at_pos(&head, 20, 2);
    display(head);

    delete_first(&head);
    display(head);

    return 0;
}
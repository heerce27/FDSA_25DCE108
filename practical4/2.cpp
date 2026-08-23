#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insert_at_beginning(Node** head, int data)
{
    Node* newn = new Node();
    newn->data = data;
    newn->next = *head;
    *head = newn;
}
void print_list(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void insert_at_end(Node** head,int val)
{
    Node* newn = new Node();
    newn->data=val;
    newn->next=NULL;
    if(*head==NULL)
    {
        *head=newn;
         return;
    }
    Node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newn;
}
void insert_atpos(Node** head,int val,int pos)
{
    if(pos==1)
    {
        insert_at_beginning(head,val);
        return;
    }
    Node *newn=new Node();
    newn->data=val;
    if(*head==NULL){
        *head=newn;
         return;
    }
    Node *temp = *head;
    for(int i=0;i<pos-1;i++)
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    { 
        printf("Invalid position\n"); return; 
    }
    newn->next = temp->next;
    temp->next = newn;
}

void deletion_by_value(Node** head,int val){
    if(*head==NULL){
        cout<<"List is empty";
        return;
    }

    Node *temp= *head;
    Node *p = nullptr;
    
    while(temp->next!= NULL && temp->data!=val){
        p=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Value not found";
        return;
    }
    if(p == NULL)
    {
        *head = temp->next;
    }
    else
    {
        p->next = temp->next;
    }
    delete temp;
    cout << "Patient deleted successfully\n";
}

void reverse_print(Node* head)
{
    if (head == NULL)
        return;
    reverse_print(head->next);
    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;
    int choice;
    do
    {
       cout << "\n1. Critical patient";
        cout << "\n2. Routine patient";
        cout << "\n3. Priority patient";
        cout << "\n4. Delete patient";
        cout << "\n5. Forward display";
        cout << "\n6. Reverse display";
        cout << "\n7. Exit";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    cout<<"Enter the number of critical patients: ";
                    int n;
                    cin>>n;
                    cout<<"Enter the patient IDs: ";    
                    for(int i=0;i<n;i++)
                    {
                        int id;
                        cin>>id;
                        insert_at_beginning(&head,id);
                    }
                    break;
                }
            case 2:
               {
                    cout<<"Enter the number of routine patients: ";
                    int n;
                    cin>>n;
                    cout<<"Enter the patient IDs: ";    
                    for(int i=0;i<n;i++)
                    {
                        int id;
                        cin>>id;
                        insert_at_end(&head,id);
                    }
                    break;
                }
            case 3:
                {
                    cout<<"Enter the number of patients with priority: ";
                    int n;
                    cin>>n;
                    cout<<"Enter the patient IDs: ";    
                    for(int i=0;i<n;i++)
                    {
                        int id;
                        cin>>id;
                        cout<<"Enter the position to insert patient ID "<<id<<": ";
                        int pos;
                        cin>>pos;
                        insert_atpos(&head,id,pos);
                    }
                    break;
                }
            case 4:
            {
                cout<<"Enter value to delete:";
                int val;
                cin>>val;
                deletion_by_value(&head,val);
                print_list(head);
                break;
            }
            case 5:
            {
                print_list(head);
                break;
            }
            case 6:
            {
                reverse_print(head);
                break;
            }
            case 7:
            {
                cout<<"Exiting";
                break;
            }
            default:
                cout<<"Invalid choice\n";
        }
    } while (choice !=7);
    cout<<"\nFinal list of patients: ";
    print_list(head);
}
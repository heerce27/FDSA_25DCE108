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
void insert_atpos(Node** head, int val, int pos)
{
    if(pos <= 0)
    {
        cout << "Invalid position\n";
        return;
    }
    if(pos == 1)
    {
        insert_at_beginning(head, val);
        return;
    }
    if(*head == NULL)
    {
        cout << "Invalid position\n";
        return;
    }
    Node* temp = *head;
    
    for(int i = 1; i < pos - 1; i++)
    {
        if(temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    Node* newn = new Node();
    newn->data = val;
    newn->next = temp->next;
    temp->next = newn;
}
int main()
{
    Node* head = NULL;
    int choice;
    do
    {
        cout<<"1.critical patients \n2.Routine patients \n3.patient with a priority \n4. Exit\nEnter your choice: ";
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
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    } while (choice != 4);
    cout<<"\nFinal list of patients: ";
    print_list(head);
}
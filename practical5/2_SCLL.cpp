// #include<iostream>
// using namespace std;

// struct Node
// {
//    int data;
//    Node *next;
// };

// void insert_at_begining(Node **head,int val)
// {
//     Node *newn=new Node();
//     newn->data=val;
//     if (*head == NULL)
//     {
//         newn->next = newn;
//         *head = newn;
//         return;
//     }

//     newn->next=*head;
//     *head=newn;
//     Node *temp=*head;
//     while(temp->next!=*head){
//         temp=temp->next;
//     }
//     temp->next=newn;
// }

// void insert_at_end(Node **head,int val)
// {
//     Node *newn=new Node();
//     newn->data=val;
//     if (*head == NULL)
//     {
//         newn->next = newn;
//         *head = newn;
//         return;
//     }
//     Node *temp = *head;
//     while(temp->next!=*head){
//         temp=temp->next;
//     }
//     temp->next=newn;
//     newn->next=*head;
// }

// void insert_after_std(Node **head, int std, int val)
// {
//     if (*head == NULL)
//     {
//         cout<<"Circle is empty\n";
//         return;
//     }
//     Node *temp = *head;
//     do{
//         if(temp->data==std){
//             Node *newn = new Node();
//             newn->data = val;
//             newn->next = temp->next;
//             temp->next = newn;
//             return;
//         }
//         temp=temp->next;
//     }while(temp!=*head);
//     cout<<"Student not found!\n";
// }

// void delete_std(Node **head,int val)
// {
//     if(*head==NULL){
//         cout<<"Circle is empty.\n";
//         return;
//     }
//     Node *cur=*head;
//     Node *prev=NULL;
//     if(cur->next==*head){
//         if(cur->data==val){
//             delete cur;
//             *head=NULL;
//             return;
//         }
//     }
//     do{
//         if(cur->data==val)
//         {
            
//             break;
//         }
//          prev=cur;

//     } 
// }
// int main()
// { 
    
// }

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void insert_at_beginning(Node **head, int val)
{
    Node *newn = new Node();
    newn->data = val;
    // Empty circle
    if (*head == NULL)
    {
        newn->next = newn;
        *head = newn;
        return;
    }
    newn->next = *head;
    Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newn;
    *head = newn;
}
// Insert at end
void insert_at_end(Node **head, int val)
{
    Node *newn = new Node();
    newn->data = val;
    if (*head == NULL)
    {
        newn->next = newn;
        *head = newn;
        return;
    }
    Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newn;
    newn->next = *head;
}

// Insert after a particular student
void insert_after_std(Node **head, int std, int val)
{
    if (*head == NULL)
    {
        cout << "Circle is empty.\n";
        return;
    }
    Node *temp = *head;
    do
    {
        if (temp->data == std)
        {
            Node *newn = new Node();
            newn->data = val;

            newn->next = temp->next;
            temp->next = newn;
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    cout << "Student not found!\n";
}

// Delete a student
void delete_std(Node **head, int val)
{
    if (*head == NULL)
    {
        cout << "Circle is empty.\n";
        return;
    }
    Node *cur = *head;
    Node *prev = NULL;
    // Only one student
    if (cur->next == *head)
    {
        if (cur->data == val)
        {
            delete cur;
            *head = NULL;
        }
        else
        {
            cout << "Student not found!\n";
        }
        return;
    }
    // Find the node
    do
    {
        if (cur->data == val)
            break;
        prev = cur;
        cur = cur->next;

    } while (cur != *head);
    // Student not found
    if (cur == *head && cur->data != val)
    {
        cout << "Student not found!\n";
        return;
    }
    // Deleting head
    if (cur == *head)
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = cur->next;
        last->next = *head;
        delete cur;
    }
    else
    {
        // Normal deletion
        prev->next = cur->next;
        delete cur;
    }
}
// Display circle
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Circle is empty.\n";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node *head = NULL;
    insert_at_end(&head, 10);
    cout << "After joining 10: ";
    display(head);
    insert_at_end(&head, 20);
    cout << "After joining 20: ";
    display(head);
    insert_at_beginning(&head, 5);
    cout << "After joining 5 at beginning: ";
    display(head);
    insert_after_std(&head, 10, 15);
    cout << "After joining 15 after 10: ";
    display(head);
    delete_std(&head, 10);
    cout << "After student 10 leaves: ";
    display(head);
    delete_std(&head, 5);
    cout << "After student 5 leaves: ";
    display(head);
    delete_std(&head, 20);
    cout << "After student 20 leaves: ";
    display(head);
    return 0;
}
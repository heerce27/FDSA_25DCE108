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
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    Node* head = NULL;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insert_at_end(&head, data);
    }
    print_list(head);
    return 0;
}
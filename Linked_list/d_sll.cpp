#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

void delete_at_begining(Node** head){
    Node *temp=*head;
    head=head->next;
    free(temp);
}
void print(Node *head){
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main(){
    int n;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        
    }
}

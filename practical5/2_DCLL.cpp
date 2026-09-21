#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
// Insert at beginning
void insert_at_beginning(Node **head, int val)
{
    Node *newn = new Node();
    newn->data = val;
    if (*head == NULL)
    {
        newn->next = newn;
        newn->prev = newn;
        *head = newn;
        return;
    }
    Node *last = (*head)->prev;
    newn->next = *head;
    newn->prev = last;
    last->next = newn;
    (*head)->prev = newn;
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
        newn->prev = newn;
        *head = newn;
        return;
    }
    Node *last = (*head)->prev;
    newn->next = *head;
    newn->prev = last;
    last->next = newn;
    (*head)->prev = newn;
}

// Insert after a student
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
            newn->prev = temp;
            temp->next->prev = newn;
            temp->next = newn;
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    cout << "Student not found!\n";
}

// Delete student
void delete_std(Node **head, int val)
{
    if (*head == NULL)
    {
        cout << "Circle is empty.\n";
        return;
    }
    Node *cur = *head;
    do
    {
        if (cur->data == val)
            break;
        cur = cur->next;
    } while (cur != *head);
    // Student not found
    if (cur->data != val)
    {
        cout << "Student not found!\n";
        return;
    }
    // Only one node
    if (cur->next == cur)
    {
        delete cur;
        *head = NULL;
        return;
    }
    // Connect previous and next nodes
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    // If deleting head
    if (cur == *head)
    {
        *head = cur->next;
    }
    delete cur;
}

// Display
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
    cout << "After joining 5: ";
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
    return 0;
}